#include "Log.h"
void InitLog(void){
    Log("Initializing Log");
}
void Log(const char* message){
  std::cout << message << std::endl;
}

void Log(const int message){
  std::cout << message << std::endl;
}