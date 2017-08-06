#include <iostream>
#include <iomanip>

#include <string.h>
#include <unistd.h>

#include <console.hpp>
#include <toyhack.h>

#include "lib/libyokai-watch.h"
#include "../yokai-medal.h"


TCommandDescription cmd_descriptions[] = {
                      {"help", "Print help"},
                      {"list", "List all medal ID"},
                      {"insert", "Insert medal <id>"},
                      {"eject", "Eject medal."},
                      {"exit", "Exit from this console"},
                      {NULL, NULL}
};

static void print_medal_list(){
  std::cout << "Medal list:" << std::endl;

  for(int Cnt = 0; Cnt < MEDAL_MAX_ID; Cnt++){
    std::cout << std::setw(2) << Cnt << ": " <<
                               medal_list[Cnt].name << std::endl;
  }

}

static void print_medal(const char *label, int id){
  std::cout << label << ": ";

  if(id == -1){
    std::cout << "N/A";
  }
  else{
    std::cout << medal_list[id].name;
  }

  std::cout << std::endl;
}

int main(int argc, char *argv[]){

#ifndef CONSOLE_TEST
  if(SetupGPIO() != TOYHACK_SUCCEEDED){
    std::cerr << "Could not initialize libyokai-watch." << std::endl;
    return TOYHACK_ERROR;
  }
#endif

  TConsole console(cmd_descriptions);

  std::cout << "Yokai Watch DX management console" << std::endl;
  std::cout << "Copyright (C) 2017 Yasumasa Suenaga" << std::endl;
  std::cout << std::endl;

  while(true){
    const char *cmd = console.GetCommand("yokai-dx> ");

    if(strcmp(cmd, "help") == 0){
      console.PrintHelp();
    }
    else if(strcmp(cmd, "list") == 0){
      print_medal_list();
    }
    else if(strcmp(cmd, "insert") == 0){
      int id = -1;

      /* Read medal ID */
      id = console.GetNextArgAsInt();
      print_medal("Medal", id);

#ifndef CONSOLE_TEST
      if(SetMedal(id) != TOYHACK_SUCCEEDED){
        std::cerr << "Cannot set Yokai Medal." << std::endl;
      }
#endif

    }
    else if(strcmp(cmd, "eject") == 0){

#ifndef CONSOLE_TEST
      if(EjectMedal() != TOYHACK_SUCCEEDED){
        std::cerr << "Cannot eject Yokai Medal." << std::endl;
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

