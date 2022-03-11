#pragma once
 #include<memory>

#include"Core.h"
#include"spdlog/spdlog.h"



namespace Neko {
	class NEKO_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;

	};
}

#define NEKO_CORE_TRACE(...)	::Neko::Log::getCoreLogger()->trace(__VA_ARGS__)
#define NEKO_CORE_WARN(...)		::Neko::Log::getCoreLogger()->warn(__VA_ARGS__)
#define NEKO_CORE_INFO(...)		::Neko::Log::getCoreLogger()->info(__VA_ARGS__)
#define NEKO_CORE_ERROR(...)	::Neko::Log::getCoreLogger()->error(__VA_ARGS__)
#define NEKO_CORE_FATAL(...)	::Neko::Log::getCoreLogger()->critical(__VA_ARGS__)

#define NEKO_CLIENT_TRACE(...)		::Neko::Log::getClientLogger()->trace(__VA_ARGS__)
#define NEKO_CLIENT_WARN(...)		::Neko::Log::getClientLogger()->warn(__VA_ARGS__)
#define NEKO_CLIENT_INFO(...)		::Neko::Log::getClientLogger()->info(__VA_ARGS__)
#define NEKO_CLIENT_ERROR(...)		::Neko::Log::getClientLogger()->error(__VA_ARGS__)
#define NEKO_CLIENT_FATAL(...)		::Neko::Log::getClientLogger()->critical(__VA_ARGS__)

