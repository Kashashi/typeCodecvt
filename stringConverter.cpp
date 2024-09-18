#include "stringConverter.h"
#include <string>
#include <stdexcept>

std::string utf16_to_utf8(const std::u16string& utf16_str) {
	std::string utf8_str;
	for (char16_t ch : utf16_str) {
		if (ch < 0x80) {
			utf8_str.push_back(static_cast<char>(ch));
		} else if (ch < 0x800) {
			utf8_str.push_back(static_cast<char>((ch >> 6) | 0xC0));
			utf8_str.push_back(static_cast<char>((ch & 0x3F) | 0x80));
		} else {
			utf8_str.push_back(static_cast<char>((ch >> 12) | 0xE0));
			utf8_str.push_back(static_cast<char>(((ch >> 6) & 0x3F) | 0x80));
			utf8_str.push_back(static_cast<char>((ch & 0x3F) | 0x80));
		}
	}
	return utf8_str;
}

std::u16string utf8_to_utf16(const std::string& utf8_str) {
	std::u16string utf16_str;
	for (size_t i = 0; i < utf8_str.size(); ++i) {
		char16_t ch = utf8_str[i];
		if ((ch & 0x80) == 0) {
			utf16_str.push_back(ch);
		} else if ((ch & 0xE0) == 0xC0) {
			char16_t ch1 = utf8_str[i++];
			char16_t ch2 = utf8_str[i];
			utf16_str.push_back(((ch1 & 0x1F) << 6) | (ch2 & 0x3F));
		} else if ((ch & 0xF0) == 0xE0) {
			char16_t ch1 = utf8_str[i++];
			char16_t ch2 = utf8_str[i++];
			char16_t ch3 = utf8_str[i];
			utf16_str.push_back(((ch1 & 0x0F) << 12) | ((ch2 & 0x3F) << 6) | (ch3 & 0x3F));
		}
	}
	return utf16_str;
}

std::wstring u16string_to_wstring(const std::u16string& u16str){
    std::wstring wstr;
    for (char16_t ch : u16str) {
        wstr.push_back(static_cast<wchar_t>(ch));
    }
    return wstr;
}

std::wstring utf8_to_wstring(const std::string& str){
	return u16string_to_wstring(utf8_to_utf16(str));
}