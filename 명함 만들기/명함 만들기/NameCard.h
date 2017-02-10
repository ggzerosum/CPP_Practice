#pragma once

namespace My_NameSpace
{
	class NAMECARD
	{
	private:
		char* m_Name;
		char* m_NameOfCompany;
		char* m_Tel;
		int m_Rank;
		void StrToMembersWithNew(char* &destination, const char* source);
	public:
		//생성자 기본
		NAMECARD(void);
		//생성자
		NAMECARD(const char* name, const char* nameOfCompany, const char* tel, int rank);
		//복사 생성자
		NAMECARD(const NAMECARD &copy);
		//소멸자
		~NAMECARD(void);

		void ShowNameCardInfo(void);
	};
}