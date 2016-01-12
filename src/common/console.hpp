#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <string>
#include <vector>
#include <deque>


typedef struct{
  const char *cmd;
  const char *description;
} TCommandDescription;


class TConsole{

  private:
    std::vector<const TCommandDescription *> valid_commands;
    std::deque<std::string> args;

    std::string current_cmd;
    std::deque<std::string>::iterator arg_itr;

    void BuildInputCommand(std::string cmdline);

  public:
    TConsole(const TCommandDescription *commands);
    ~TConsole(){};

    const char *GetCommand(const char *prompt);

    inline const char *GetNextArgAsString(void){
      if(arg_itr == args.end()){
        throw -1;
      }
      else{
        return (arg_itr++)->c_str();
      }
    }

    inline const int GetNextArgAsInt(void){
      if(arg_itr == args.end()){
        throw -1;
      }
      else{
        return std::stoi(*(arg_itr++));
      }
    }

    inline const bool GetNextArgAsOnOff(void){
      if(arg_itr == args.end()){
        throw -1;
      }
      else{
        std::string arg = *(arg_itr++);
        if(arg == "on"){
          return true;
        }
        else if(arg == "off"){
          return false;
        }
        else{
          throw -1;
        }
      }
    }

    void PrintHelp(void);

};

#endif // CONSOLE_HPP
