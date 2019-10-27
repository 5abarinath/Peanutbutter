#pragma once

#include "Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Peanutbutter
{
	class PB_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define PB_CORE_TRACE(...)   ::Peanutbutter::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PB_CORE_INFO(...)    ::Peanutbutter::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PB_CORE_WARN(...)    ::Peanutbutter::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PB_CORE_ERROR(...)   ::Peanutbutter::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PB_CORE_CRITICAL(...)   ::Peanutbutter::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define PB_TRACE(...)        ::Peanutbutter::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PB_INFO(...)         ::Peanutbutter::Log::GetClientLogger()->info(__VA_ARGS__)
#define PB_WARN(...)         ::Peanutbutter::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PB_ERROR(...)        ::Peanutbutter::Log::GetClientLogger()->error(__VA_ARGS__)
#define PB_CRITICAL(...)        ::Peanutbutter::Log::GetClientLogger()->critical(__VA_ARGS__)

