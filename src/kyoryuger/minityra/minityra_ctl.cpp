#include <iostream>
#include <iomanip>

#include <string.h>
#include <unistd.h>

#include <console.hpp>
#include <toyhack.h>

#include "libminityra.h"
#include "../judenchi.h"


TCommandDescription cmd_descriptions[] = {
                      {"help", "Print help."},
                      {"list", "List all Judenchi ID."},
                      {"judenchi", "Set judenchi <id>"},
                      {"gabu", "Gum the Judenchi."},
                      {"mode", "Set mode <overcharge|carnival>."},
                      {"gaburevolver", "Dock gaburevolver <on|off>"},
                      {"trigger", "Push trigger switch."},
                      {"side", "Push side switch."},
                      {"henshin", "Change to the Kyoryu-Red Carnival."},
                      {"kamichange", "Kamitsuki Change <id1> <id2> <id3>."},
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
    std::cerr << "Could not initialize libminityra." << std::endl;
    return TOYHACK_ERROR;
  }
#endif

  TConsole console(cmd_descriptions);

  std::cout << "Minityra management console" << std::endl;
  std::cout << "Copyright (C) 2016 Yasumasa Suenaga" << std::endl;
  std::cout << std::endl;

  while(true){
    const char *cmd = console.GetCommand("minityra> ");

    if(strcmp(cmd, "help") == 0){
      console.PrintHelp();
    }
    else if(strcmp(cmd, "list") == 0){
      print_judenchi_list();
    }
    else if(strcmp(cmd, "judenchi") == 0){
      int id = -1;

      /* Read Judenchi ID */
      try{
        id = console.GetNextArgAsInt();

        if(!ID_ISIN(id)){
          throw -1;
        }

      }
      catch(...){
        std::cerr << "Invalid Judenchi ID." << std::endl;
        continue;
      }

      print_judenchi("Judenchi", id);

#ifndef CONSOLE_TEST
      if(SetJudenchi(id) != TOYHACK_SUCCEEDED){
        std::cerr << "Cannot set Judenchi." << std::endl;
      }
#endif

    }
    else if(strcmp(cmd, "gabu") == 0){

#ifndef CONSOLE_TEST
      if(Gabu() != TOYHACK_SUCCEEDED){
        std::cerr << "Cannot send gabu command." << std::endl;
      }
#endif

    }
    else if(strcmp(cmd, "mode") == 0){
      int mode = -1;

      try{
        const char *mode_str = console.GetNextArgAsString();

        if(strcmp(mode_str, "overcharge") == 0){
          mode = MODE_OVERCHARGE;
        }
        else if(strcmp(mode_str, "carnival") == 0){
          mode = MODE_CARNIVAL;
        }
        else{
          throw -1;
        }

      }
      catch(...){
        std::cerr << "Invalid mode." << std::endl;
      }

#ifndef CONSOLE_TEST
      if(Kururincho(mode) != TOYHACK_SUCCEEDED){
        std::cerr << "Cannot send kururincho command." << std::endl;
      }
#endif

    }
    else if(strcmp(cmd, "gaburevolver") == 0){
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
      if(isOn && (DockGaburevolver() != TOYHACK_SUCCEEDED)){
        std::cerr << "Cannot dock to gaburevolver." << std::endl;
      }
      else if(!isOn && (UndockGaburevolver() != TOYHACK_SUCCEEDED)){
        std::cerr << "Cannot undock from gaburevolver." << std::endl;
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
    else if(strcmp(cmd, "side") == 0){

#ifndef CONSOLE_TEST
      if(SideSwitch() != TOYHACK_SUCCEEDED){
        std::cerr << "Cannot send side switch command." << std::endl;
      }
#endif

    }
    else if(strcmp(cmd, "henshin") == 0){
      SetJudenchi(-1);
      Kururincho(MODE_CARNIVAL);
      sleep(1);
      SetJudenchi(55); // Carnival Judenchi
      Gabu();
      sleep(10);
      Trigger();
    }
    else if(strcmp(cmd, "kamichange") == 0){
      SideSwitch();
      sleep(3);
      SetJudenchi(-1);
      sleep(1);

      for(int Cnt = 0; Cnt < 3; Cnt++){
        int id = -1;

        /* Read Judenchi ID */
        try{
          id = console.GetNextArgAsInt();

          if(!ID_ISIN(id)){
            throw -1;
          }

        }
        catch(...){
          std::cerr << "Invalid Judenchi ID." << std::endl;
          break;
        }

        SetJudenchi(id);
        sleep(1);
        Gabu();
        sleep(2);
      }

      Trigger();
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

