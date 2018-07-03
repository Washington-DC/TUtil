#pragma once
#include "iostream"
#include "tchar.h"
#include <memory>

#define DLL_EXPORT		_declspec(dllexport)

#define TUtil_API		_declspec(dllexport)

#define EXTERN_C_BEGIN	extern "C" {
#define EXTERN_C_END	}


#ifdef _UNICODE
#	define TString		std::wstring
#else
#	define TString		std::string
#endif 


#ifndef TCHAR
#	ifdef _UNICODE
#		define TCHAR	wchar_t
#	else
#		define TCHAR	char
#	endif 
#endif
