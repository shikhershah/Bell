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
   Engine_TRACE("Reached CreateApp");

   Bell::Application* app = Bell::CreateApp();
   Engine_TRACE("Start Running App");
   app->Run();

   return 0;

}
