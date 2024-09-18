#ifndef __STRINGCONVERTER_H_
#define __STRINGCONVERTER_H_
#include <string>

std::string utf16_to_utf8(const std::u16string& utf16_str);
std::u16string utf8_to_utf16(const std::string& utf8_str);
std::wstring u16string_to_wstring(const std::u16string& u16str);
std::wstring utf8_to_wstring(const std::string& str);

#endif//__STRINGCONVERTER_H_