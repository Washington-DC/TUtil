#include "stdafx.h"
#include "StringUtil.h"

std::wstring StringUtil::As_WStringFromString(std::string const &s) {
	auto len = ::MultiByteToWideChar(CP_ACP, 0, s.c_str(), s.size(), NULL, 0);
	std::unique_ptr<WCHAR[]> result(new WCHAR[len + 1]);
	::MultiByteToWideChar(CP_ACP, 0, s.c_str(), s.size(), result.get(), len + 1);
	result.get()[len] = 0;
	return std::wstring(result.get());
}


std::string StringUtil::As_StringFromWstring(std::wstring const &s) {
	auto len = WideCharToMultiByte(CP_ACP, 0, s.c_str(), s.size(), nullptr, 0, nullptr, nullptr);
	std::unique_ptr<char[]> result(new char[len + 1]);
	WideCharToMultiByte(CP_ACP, 0, s.c_str(), s.size(), result.get(), len + 1, nullptr, nullptr);
	result.get()[len] = 0;
	return std::string(result.get());
}

std::string StringUtil::As_Utf8FromWstring(std::wstring const &s) {
	auto len = WideCharToMultiByte(CP_UTF8, 0, s.c_str(), s.size(), nullptr, 0, nullptr, nullptr);
	std::unique_ptr<char[]> result(new char[len + 1]);
	WideCharToMultiByte(CP_UTF8, 0, s.c_str(), s.size(), result.get(), len + 1, nullptr, nullptr);
	result.get()[len] = 0;
	return std::string(result.get());
}

std::string StringUtil::As_Utf8FromString(std::string const &s) {
	return As_Utf8FromWstring(As_WStringFromString(s));
}

std::wstring StringUtil::As_WStringFromUtf8(std::string const &s) {
	auto len = ::MultiByteToWideChar(CP_UTF8, 0, s.c_str(), s.size(), NULL, 0);
	std::unique_ptr<WCHAR[]> result(new WCHAR[len + 1]);
	::MultiByteToWideChar(CP_UTF8, 0, s.c_str(), s.size(), result.get(), len + 1);
	result.get()[len] = 0;
	return std::wstring(result.get());
}

std::string StringUtil::As_StringFromUtf8(std::string const &s) {
	return As_StringFromWstring(As_WStringFromUtf8(s));
}
