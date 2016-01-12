#include <string>
#include <iostream>
#include <sstream>
#include <deque>

#include "console.hpp"


TConsole::TConsole(const TCommandDescription *commands)
                      : valid_commands(), args(), current_cmd(), arg_itr(){

  while(commands->cmd != NULL){
    valid_commands.push_back(commands++);
  }

}

void TConsole::BuildInputCommand(std::string cmdline){
  std::stringstream stm(cmdline);
  std::string element;
  this->args.clear();

  stm >> this->current_cmd;

  auto itr = valid_commands.begin();
  for(;itr != valid_commands.end(); itr++){

    if((*itr)->cmd == this->current_cmd){
      break;
    }

  }

  if(itr == valid_commands.end()){
    throw "Invalid command";
  }

  while(stm >> element){
    args.push_back(element);
  }

  this->arg_itr = args.begin();
}

const char *TConsole::GetCommand(const char *prompt){
  std::string cmd;

  while(true){
    std::cout << prompt;
    getline(std::cin, cmd);

    if(!cmd.empty()){

      try{
        BuildInputCommand(cmd);
        break;
      }
      catch(const char *msg){
        std::cerr << msg << std::endl;
      }

    }

  }

  return this->current_cmd.c_str();
}

void TConsole::PrintHelp(void){
  std::cout << "Help:" << std::endl;

  for(auto itr = valid_commands.begin(); itr != valid_commands.end(); itr++){
    std::cout << "  " << (*itr)->cmd <<
                             " - " << (*itr)->description << std::endl;
  }

}

