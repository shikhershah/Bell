#ifndef LOGGER_H
#define LOGGER_H

#include "spdlog/spdlog.h"



namespace Bell
{

   
   class Log
   {

      private:
         static std::shared_ptr<spdlog::logger> EngineLogger;
         static std::shared_ptr<spdlog::logger> GameLogger;

      public:

         static void init();

         static std::shared_ptr<spdlog::logger>& GetEngineLogger()
         {

            return EngineLogger;
         }

         static std::shared_ptr<spdlog::logger>& GetGameLogger()
         {
            return GameLogger;
         }
      

   };


}


#define Engine_TRACE(...)       ::Bell::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define Engine_INFO(...)        ::Bell::Log::GetEngineLogger()->info(__VA_ARGS__)
#define Engine_WARN(...)        ::Bell::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define Engine_ERROR(...)       ::Bell::Log::GetEngineLogger()->error(__VA_ARGS__)

#define Game_TRACE(...)         ::Bell::Log::GetGameLogger()->trace(__VA_ARGS__) 
#define Game_INFO(...)          ::Bell::Log::GetGameLogger()->info(__VA_ARGS__) 
#define Game_WARN(...)          ::Bell::Log::GetGameLogger()->warn(__VA_ARGS__) 
#define Game_ERROR(...)         ::Bell::Log::GetGameLogger()->error(__VA_ARGS__) 


#endif //LOGGER_H
