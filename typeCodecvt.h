#ifndef __TYPECODECVT__
#define __TYPECODECVT__
#include <codecvt>
#include <locale>
#include <string>


namespace 黃月蘭的動態庫{
	class 文字轉換器{
	public:
		static 文字轉換器& 獲得文字轉換器();
		std::wstring 字元陣列轉寬字串(const char* 輸入字元陣列);
		char* 寬字串轉字元陣列(std::wstring 輸入寬字串);
		
	private:
		文字轉換器() = default;
		文字轉換器(const 文字轉換器& 複製目標) = default;
		文字轉換器& operator=(const 文字轉換器& 複製目標) = delete;
	};
}
#endif//__TYPECODECVT__