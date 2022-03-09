#pragma once
#ifdef NEKO_PLATFORM_WINDOWS
#ifdef NEKO_BUILD_DLL
	#define NEKO_API _declspec(dllexport)
#else NEKO_API _declspec(dllimport)
#endif
#else 
#error Neko only support windows
#endif