#pragma once
#include "Common.h"

namespace My_NameSpace
{
	class String : public COMMON
	{
	private:
		char* str;
		size_t len;

	public:
		String(const char* source = nullptr); //생성시.
		String(const String &ref); //복사 생성자.
		~String(); //소멸자.

		String operator+(const String &ref) const;							//+		멤버
		String &operator+=(const String &ref);								//+=	멤버
		String &operator=(const String &ref);								//=		멤버
		friend bool operator==(const String &left, const String &right);	//==	전역
		friend bool operator!=(const String &left, const String &right);	//!=	전역
		friend ostream &operator<<(ostream &left, const String &right);		//cout	전역
		friend istream &operator>>(istream &left, String &right);			//cin	전역
	};
}