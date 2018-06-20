
#include "iostream"
#include "tchar.h"
#include <memory>

#define DLL_EXPORT		_declspec(dllexport)

#define EXTERN_C_BEGIN	extern "C" {
#define EXTERN_C_END	}

#ifdef _UNICODE
#define OString		std::wstring
#define OChar		wchar_t
#else
#define OString		std::string
#define OChar		char
#endif 
