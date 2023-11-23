

#include <iostream>

#include "Logging.h"
//#include "spdlog/spdlog.h"

int main()
{

   Bell::Log::init();

   Engine_TRACE("Hello");
   

   //spdlog::info("Welcome to spdlog!");


   return 0;
}
