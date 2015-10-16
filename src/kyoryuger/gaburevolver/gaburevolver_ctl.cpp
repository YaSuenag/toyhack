#include <iostream>
#include <iomanip>

#include "libgaburevolver.h"
#include "../judenchi.h"
#include "../../toyhack.h"


static void print_help(){
  std::cout << "Help:" << std::endl;
  std::cout << "  list - List all Judenchi ID." << std::endl;
  std::cout << "  open - Open setter." << std::endl;
  std::cout << "  judenchi <lower id> <upper id> - Set judenchi." << std::endl;
  std::cout << "  close - Close setter," << std::endl;
  std::cout << "  rotate - Start rotate switch." << std::endl;
  std::cout << "  trigger - Trigger on." << std::endl;
  std::cout << "  minityra [on|off] - Dock/Undock Minityra." << std::endl;
  std::cout << "  calibur [on|off] - Dock/Undock Gaburicalibur." << std::endl;
  std::cout << "  exit - Exit from this console." << std::endl;
}

static void print_judenchi_list(){
  std::cout << "List of Judenchi:" << std::endl;

  for(int Cnt = 0; Cnt < JUDENCHI_MAX_ID; Cnt++){
    std::cout << std::setw(2) << Cnt << ": " <<
                               judenchi_list[Cnt].name << std::endl;
  }

}

static void skip_to_next_input(){
  /* Ignore another arguments. */
  while(std::cin.get() != 0x0a){}
}

static bool read_judenchi_id(int *id){
  bool parse_result = false;

  if(std::cin.peek() != 0x0a){
    std::cin >> *id;
    parse_result = !std::cin.fail();
    parse_result &= ID_ISIN(*id);
  }

  if(!parse_result){
    std::cerr << "You have to set Judenchi ID." << std::endl;
    std::cin.clear();
    skip_to_next_input();
  }

  return parse_result;
}

static void print_judenchi(const char *label, int id){
  std::cout << label << ": ";

  if(id == -1){
    std::cout << "N/A";
  }
  else{
    std::cout << judenchi_list[id].name;
  }

  std::cout << std::endl;
}

static bool read_onoff(bool *sw){
  bool result = true;
  std::string subcommand;

  if(std::cin.peek() != 0x0a){
    std::cin >> subcommand;
    result = !std::cin.fail();
  }

  if(!result){
    std::cerr << "You have to set on or off." << std::endl;
    std::cin.clear();
    skip_to_next_input();
  }
  else if(subcommand == "on"){
    *sw = true;
  }
  else if(subcommand == "off"){
    *sw = false;
  }
  else{
    std::cerr << "Invalid argument." << std::endl;
    result = false;
  }

  return result;
}

int main(int argc, char *argv[]){

  if(SetupGPIO() != TOYHACK_SUCCEEDED){
    std::cerr << "Could not initialize libgaburevolver." << std::endl;
    return TOYHACK_ERROR;
  }

  std::cout << "Gaburevolver management console" << std::endl;
  std::cout << "Copyright (C) 2015 Yasumasa Suenaga" << std::endl;
  std::cout << std::endl;

  while(true){
    std::cout << "gaburevolver> ";
    std::string cmd;
    std::cin >> cmd;

    if(cmd == "help"){
      print_help();
    }
    else if(cmd == "list"){
      print_judenchi_list();
    }
    else if(cmd == "open"){
      if(OpenSetter() != TOYHACK_SUCCEEDED){
        std::cerr << "Cannot send open command." << std::endl;
      }
    }
    else if(cmd == "judenchi"){
      int lower = -1;
      int upper = -1;
      bool parse_result;

      /* Read Judenchi ID */
      if((parse_result = read_judenchi_id(&lower))){
        parse_result &= read_judenchi_id(&upper);
      }

      if(!parse_result){
        continue;
      }

      if(SetJudenchi(lower, upper) != TOYHACK_SUCCEEDED){
        std::cerr << "Cannot set Judenchi." << std::endl;
      }

      print_judenchi("lower", lower);
      print_judenchi("upper", upper);
    }
    else if(cmd == "close"){
      if(CloseSetter() != TOYHACK_SUCCEEDED){
        std::cerr << "Cannot send close command." << std::endl;
      }
    }
    else if(cmd == "rotate"){
      if(Rotate() != TOYHACK_SUCCEEDED){
        std::cerr << "Cannot send rotate command." << std::endl;
      }
    }
    else if(cmd == "trigger"){
      if(Trigger() != TOYHACK_SUCCEEDED){
        std::cerr << "Cannot send trigger command." << std::endl;
      }
    }
    else if(cmd == "minityra"){
      bool isOn;

      if(read_onoff(&isOn)){
        if(isOn && (DockMinityra() != TOYHACK_SUCCEEDED)){
          std::cerr << "Cannot dock to minityra." << std::endl;
        }
        else if(!isOn && (UndockMinityra() != TOYHACK_SUCCEEDED)){
          std::cerr << "Cannot undock from minityra." << std::endl;
        }
      }

    }
    else if(cmd == "calibur"){
      bool isOn;

      if(read_onoff(&isOn)){
        if(isOn && (DockGaburicalibur() != TOYHACK_SUCCEEDED)){
          std::cerr << "Cannot dock to Gaburicalibur." << std::endl;
        }
        else if(!isOn && (UndockGaburicalibur() != TOYHACK_SUCCEEDED)){
          std::cerr << "Cannot undock from Gaburicalibur." << std::endl;
        }
      }

    }
    else if(cmd == "exit"){
      break;
    }
    else{
      std::cerr << "Error: Unknown command." << std::endl;
    }

    skip_to_next_input();
  }

  return 0;
}

