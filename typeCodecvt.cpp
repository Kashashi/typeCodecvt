#include <typeCodecvt.h>

static std::wstring_convert<
	std::codecvt_utf8<
		typename std::wstring::value_type>,
		typename std::wstring::value_type> 
			字元陣列指針到八字元統一碼到寬字串轉換器;
			
static std::wstring_convert<
	std::codecvt_utf8<
		typename std::wstring::value_type>,
		typename std::wstring::value_type>
			&string2Unicode_82WstringConvertor
				= 字元陣列指針到八字元統一碼到寬字串轉換器;

namespace 黃月蘭的動態庫{
	
	文字轉換器& 文字轉換器::獲得文字轉換器(){
		static 文字轉換器 轉換器本人;
		return 轉換器本人;
	}/*
	void* 執行(const char* 命令, void* 輸入物件);
	void* 執行(const wchar_t* 命令, void* 輸入物件);
	void* 執行(const char* 從什麼類型, const char* 變成什麼類型, void* 輸入物件);
	void* 執行(const wchar_t* 從什麼類型, const wchar_t* 變成什麼類型, void* 輸入物件);*/
	std::wstring 文字轉換器::字元陣列轉寬字串(const char* 輸入字元陣列){
		return 字元陣列指針到八字元統一碼到寬字串轉換器.from_bytes(輸入字元陣列);
	}
	char* 文字轉換器::寬字串轉字元陣列(std::wstring 輸入寬字串){
		return 字元陣列指針到八字元統一碼到寬字串轉換器.to_bytes(輸入寬字串).data();
	}
}

namespace HahenruDynamicLibrary{
	
	textConvertor& textConvertor::getTextConvertor(){
		static textConvertor Convertor;
		return Convertor;
	}
	
	std::wstring textConvertor::string2Wstring(const char* input_string_OR_const_char_point){
		return string2Unicode_82WstringConvertor.from_bytes(input_string_OR_const_char_point);
	}
	
	char* textConvertor::wstring2String(std::wstring input_wstring_OR_const_wchar_t_point){
		return string2Unicode_82WstringConvertor.to_bytes(input_wstring_OR_const_wchar_t_point).data();
	}
}