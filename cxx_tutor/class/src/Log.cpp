#include "Log.h"


void Log::setLogLevel(int level){
    m_LogLevel = level;
}

void Log::Error(const char* message){
    std::cout<<"[ERROR]"<<message<<std::endl;
}

void Log::Warnings(const char* message){
    std::cout<<"[WARNING]"<<message<<std::endl;
}

void Log::Info(const char* message){
    std::cout<<"[INFO]"<<message<<std::endl;
}


