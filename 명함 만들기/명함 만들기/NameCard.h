#pragma once

namespace My_NameSpace
{
	class NAMECARD
	{
	private:
		char* m_Name;
		char* m_NameOfCompany;
		char* m_Tel;
		const int m_Rank;
		void StrToMembersWithNew(char* &destination, const char* source);
	public:
		NAMECARD(const char* name, const char* nameOfCompany, const char* tel, int rank);
		~NAMECARD(void);
		void ShowNameCardInfo(void);
	};
}