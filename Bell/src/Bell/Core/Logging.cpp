#include "Logging.h"
#include <iostream>

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

namespace Bell
{
   std::shared_ptr<spdlog::logger> Log::EngineLogger;
   std::shared_ptr<spdlog::logger> Log::GameLogger;

   void Log::init()
   {

      //std::cout << "Hello World"; 
      spdlog::set_pattern("%^[%T] %n: %v%$");

      EngineLogger = spdlog::stdout_color_mt("Bell");
      EngineLogger->set_level(spdlog::level::trace);

      //GameLogger 
      //GameLogger->set_level(spdlog::level::trace);
   }
}
