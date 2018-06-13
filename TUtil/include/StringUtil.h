
#include "Base.h"

class DLL_EXPORT StringUtil
{
	static std::wstring As_WStringFromString(std::string const &s);

	static std::string As_StringFromWstring(std::wstring const &s);

	static std::string As_Utf8FromWstring(std::wstring const &s);

	static std::string As_Utf8FromString(std::string const &s);

	static std::wstring As_WStringFromUtf8(std::string const &s);

	static std::string As_StringFromUtf8(std::string const &s);
};


