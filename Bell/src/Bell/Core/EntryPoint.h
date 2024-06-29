#include <iostream>
#include <stdlib.h>
//#include <algorithm>

#include "spdlog/spdlog.h"
#include "Logging.h"
#include "Application.h"


extern Bell::Application* Bell::CreateApp();

int main()
{

   //spdlog::info("Welcome to spdlog!");
   Bell::Log::init();
   Engine_TRACE("Hello");

   Bell::Application* app = Bell::CreateApp();
   app->Run();

   return 0;

}
