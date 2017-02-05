#include "includes.h"

namespace My_NameSpace
{
	void NAMECARD::StrToMembersWithNew(char* &destination, const char* source)
	{
		size_t size;
		size = strlen(source) + 1;
		destination = new char[size];
		strcpy_s(destination, size, source);
	}

	NAMECARD::NAMECARD(const char* name, const char* nameOfCompany, const char* tel, int rank)
		:m_Rank(rank)
	{
		
		StrToMembersWithNew(m_Name, name);
		StrToMembersWithNew(m_NameOfCompany, nameOfCompany);
		StrToMembersWithNew(m_Tel, tel);
	}

	NAMECARD::~NAMECARD(void)
	{
		delete[] m_Name;
		delete[] m_NameOfCompany;
		delete[] m_Tel;

		cout << "소멸자 호출!" << endl;
	}

	void NAMECARD::ShowNameCardInfo(void)
	{
		namespace ns = My_EnumSpace;

		cout << "이름: " << m_Name << endl;
		cout << "회사: " << m_NameOfCompany << endl;
		cout << "전화번호: " << m_Tel << endl;
		cout << "직급: ";

		switch (m_Rank)
		{
		case ns::CLERK:
			cout << "사원" << endl;
			break;

		case ns::SENIOR:
			cout << "선임" << endl;
			break;

		case ns::ASSIST:
			cout << "대리" << endl;
			break;

		case ns::MANAGER:
			cout << "지점장" << endl;
			break;

		default:
			cout << "오류" << endl;
			break;
		}

		cout << endl;
	}
}