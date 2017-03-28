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
		String(const char* source = nullptr); //������.
		String(const String &ref); //���� ������.
		~String(); //�Ҹ���.

		String operator+(const String &ref) const;							//+		���
		String &operator+=(const String &ref);								//+=	���
		String &operator=(const String &ref);								//=		���
		friend bool operator==(const String &left, const String &right);	//==	����
		friend bool operator!=(const String &left, const String &right);	//!=	����
		friend ostream &operator<<(ostream &left, const String &right);		//cout	����
		friend istream &operator>>(istream &left, String &right);			//cin	����
	};
}