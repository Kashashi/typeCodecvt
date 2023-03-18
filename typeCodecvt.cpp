#include <typeCodecvt.h>

namespace 黃月蘭的動態庫{
	static std::wstring_convert<
		std::codecvt_utf8<
			typename std::wstring::value_type>,
			typename std::wstring::value_type> 
				字元陣列指針到八字元統一碼到寬字串轉換器;
	
	文字轉換器& 文字轉換器::獲得文字轉換器(){
		static 文字轉換器 轉換器本人;
		return 轉換器本人;
	}

	std::wstring 文字轉換器::字元陣列轉寬字串(const char* 輸入字元陣列){
		return 字元陣列指針到八字元統一碼到寬字串轉換器.from_bytes(輸入字元陣列);
	}
	char* 文字轉換器::寬字串轉字元陣列(std::wstring 輸入寬字串){
		return 字元陣列指針到八字元統一碼到寬字串轉換器.to_bytes(輸入寬字串).data();
	}
}