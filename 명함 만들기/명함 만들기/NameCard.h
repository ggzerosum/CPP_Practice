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
		//������ �⺻
		NAMECARD(void);
		//������
		NAMECARD(const char* name, const char* nameOfCompany, const char* tel, int rank);
		//���� ������
		NAMECARD(const NAMECARD &copy);
		//�Ҹ���
		~NAMECARD(void);

		void ShowNameCardInfo(void);
	};
}