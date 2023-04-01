#ifndef __TYPECODECVT__
#define __TYPECODECVT__
#include <codecvt>
#include <locale>
#include <string>


namespace 黃月蘭的動態庫{
	class 文字轉換器{
	public:
		static 文字轉換器& 獲得文字轉換器();/*
		void* 執行(const char* 命令, void* 輸入物件);
		void* 執行(const wchar_t* 命令, void* 輸入物件);
		void* 執行(const char* 從什麼類型, const char* 變成什麼類型, void* 輸入物件);
		void* 執行(const wchar_t* 從什麼類型, const wchar_t* 變成什麼類型, void* 輸入物件);*/
		std::wstring 字元陣列轉寬字串(const char* 輸入字元陣列);
		char* 寬字串轉字元陣列(std::wstring 輸入寬字串);
	};
}

namespace HahenruDynamicLibrary{
	class textConvertor{
	public:
		static textConvertor& getTextConvertor();/*
		void* execute(const char* command);
		void* execute(const wchar_t* command);*/
		std::wstring string2Wstring(const char* input_string_OR_const_char_point);
		char* wstring2String(std::wstring input_wstring_OR_const_wchar_t_point);
	};
}

#endif//__TYPECODECVT__