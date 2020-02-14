#pragma once
#include <memory>
#include "core.h"

#include"spdlog/spdlog.h"

namespace Crona
{
	class CRONA_API Log
	{
	public:
		Log() {}
		~Log() {}

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//core log macro
#define CA_CORE_TRACE(...) ::Crona::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CA_CORE_INFO(...) ::Crona::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CA_CORE_WARN(...) ::Crona::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CA_CORE_ERROR(...) ::Crona::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CA_CORE_FATAL(...) ::Crona::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//client log macro
#define CA_TRACE(...) ::Crona::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CA_INFO(...) ::Crona::Log::GetClientLogger()->info(__VA_ARGS__)
#define CA_WARN(...) ::Crona::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CA_ERROR(...) ::Crona::Log::GetClientLogger()->error(__VA_ARGS__)
#define CA_FATAL(...) ::Crona::Log::GetClientLogger()->fatal(__VA_ARGS__)