#include <iostream>
#include <iomanip>

#include <string.h>

#include <console.hpp>
#include <toyhack.h>

#include "lib/libgaburevolver.h"
#include "../judenchi.h"


TCommandDescription cmd_descriptions[] = {
                      {"help", "Print help."},
                      {"list", "List all Judenchi ID."},
                      {"open", "Open setter,"},
                      {"judenchi", "Set judenchi <lower id> <upper id>"},
                      {"close", "Close setter."},
                      {"rotate", "Start rotate switch."},
                      {"trigger", "Push trigger switch."},
                      {"minityra", "Dock minityra <on|off>"},
                      {"calibur", "Dock gaburicalibur <on|off>"},
                      {"exit", "Exit from this console."},
                      {NULL, NULL}
};

static void print_judenchi_list(){
  std::cout << "List of Judenchi:" << std::endl;

  for(int Cnt = 0; Cnt < JUDENCHI_MAX_ID; Cnt++){
    std::cout << std::setw(2) << Cnt << ": " <<
                               judenchi_list[Cnt].name << std::endl;
  }

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

int main(int argc, char *argv[]){

#ifndef CONSOLE_TEST
  if(SetupGPIO() != TOYHACK_SUCCEEDED){
    std::cerr << "Could not initialize libgaburevolver." << std::endl;
    return TOYHACK_ERROR;
  }
#endif

  TConsole console(cmd_descriptions);

  std::cout << "Gaburevolver management console" << std::endl;
  std::cout << "Copyright (C) 2015-2016 Yasumasa Suenaga" << std::endl;
  std::cout << std::endl;

  while(true){
    const char *cmd = console.GetCommand("gaburevolver> ");

    if(strcmp(cmd, "help") == 0){
      console.PrintHelp();
    }
    else if(strcmp(cmd, "list") == 0){
      print_judenchi_list();
    }
    else if(strcmp(cmd, "open") == 0){
#ifndef CONSOLE_TEST
      if(OpenSetter() != TOYHACK_SUCCEEDED){
        std::cerr << "Cannot send open command." << std::endl;
      }
#endif
    }
    else if(strcmp(cmd, "judenchi") == 0){
      int lower = -1;
      int upper = -1;

      /* Read Judenchi ID */
      try{
        lower = console.GetNextArgAsInt();
        upper = console.GetNextArgAsInt();

        if(!ID_ISIN(lower) || !ID_ISIN(upper)){
          throw -1;
        }

      }
      catch(...){
        std::cerr << "Invalid Judenchi ID." << std::endl;
        continue;
      }

      print_judenchi("lower", lower);
      print_judenchi("upper", upper);

#ifndef CONSOLE_TEST
      if(SetJudenchi(lower, upper) != TOYHACK_SUCCEEDED){
        std::cerr << "Cannot set Judenchi." << std::endl;
      }
#endif

    }
    else if(strcmp(cmd, "close") == 0){

#ifndef CONSOLE_TEST
      if(CloseSetter() != TOYHACK_SUCCEEDED){
        std::cerr << "Cannot send close command." << std::endl;
      }
#endif

    }
    else if(strcmp(cmd, "rotate") == 0){

#ifndef CONSOLE_TEST
      if(Rotate() != TOYHACK_SUCCEEDED){
        std::cerr << "Cannot send rotate command." << std::endl;
      }
#endif

    }
    else if(strcmp(cmd, "trigger") == 0){

#ifndef CONSOLE_TEST
      if(Trigger() != TOYHACK_SUCCEEDED){
        std::cerr << "Cannot send trigger command." << std::endl;
      }
#endif

    }
    else if(strcmp(cmd, "minityra") == 0){
      bool isOn;

      try{
        isOn = console.GetNextArgAsOnOff();
      }
      catch(...){
        std::cerr << "Invalid argument(s)." << std::endl;
        continue;
      }

#ifdef CONSOLE_TEST
      std::cout << isOn << std::endl;
#else
      if(isOn && (DockMinityra() != TOYHACK_SUCCEEDED)){
        std::cerr << "Cannot dock to minityra." << std::endl;
      }
      else if(!isOn && (UndockMinityra() != TOYHACK_SUCCEEDED)){
        std::cerr << "Cannot undock from minityra." << std::endl;
      }
#endif

    }
    else if(strcmp(cmd, "calibur") == 0){
      bool isOn;

      try{
        isOn = console.GetNextArgAsOnOff();
      }
      catch(...){
        std::cerr << "Invalid argument(s)." << std::endl;
        continue;
      }

#ifdef CONSOLE_TEST
      std::cout << isOn << std::endl;
#else
      if(isOn && (DockGaburicalibur() != TOYHACK_SUCCEEDED)){
        std::cerr << "Cannot dock to Gaburicalibur." << std::endl;
      }
      else if(!isOn && (UndockGaburicalibur() != TOYHACK_SUCCEEDED)){
        std::cerr << "Cannot undock from Gaburicalibur." << std::endl;
      }
#endif

    }
    else if(strcmp(cmd, "exit") == 0){
      break;
    }
    else{
      std::cerr << "Error: Unknown command." << std::endl;
    }

  }

  return 0;
}

