#include "includes.h"

namespace My_NameSpace
{
	namespace nsEnum = My_EnumSpace;

	void NAMECARD::StrToMembersWithNew(char* &destination, const char* source)
	{
		size_t size = strlen(source) + 1;
		destination = new char[size];
		strcpy_s(destination, size, source);
	}

	//������ �⺻
	NAMECARD::NAMECARD(void)
		:m_Rank(nsEnum::CLERK)
	{
		m_Name = NULL;
		m_NameOfCompany = NULL;
		m_Tel = NULL;
	}

	//������
	NAMECARD::NAMECARD(const char* name, const char* nameOfCompany, const char* tel, int rank)
		:m_Rank(rank)
	{
		StrToMembersWithNew(m_Name, name);
		StrToMembersWithNew(m_NameOfCompany, nameOfCompany);
		StrToMembersWithNew(m_Tel, tel);

		cout << "������ ȣ��" << endl;
	}

	//���� ������
	NAMECARD::NAMECARD(const NAMECARD &copy)
		:m_Rank(copy.m_Rank)
	{
		StrToMembersWithNew(this->m_Name, copy.m_Name);
		StrToMembersWithNew(this->m_NameOfCompany, copy.m_NameOfCompany);
		StrToMembersWithNew(this->m_Tel, copy.m_Tel);

		cout << "������ ȣ��" << endl;
	}

	//�Ҹ���
	NAMECARD::~NAMECARD(void)
	{
		delete[] m_Name;
		delete[] m_NameOfCompany;
		delete[] m_Tel;

		cout << "�Ҹ��� ȣ��!" << endl;
	}

	void NAMECARD::ShowNameCardInfo(void)
	{
		namespace ns = My_EnumSpace;

		cout << "�̸�: " << m_Name << endl;
		cout << "ȸ��: " << m_NameOfCompany << endl;
		cout << "��ȭ��ȣ: " << m_Tel << endl;
		cout << "����: ";

		switch (m_Rank)
		{
		case ns::CLERK:
			cout << "���" << endl;
			break;

		case ns::SENIOR:
			cout << "����" << endl;
			break;

		case ns::ASSIST:
			cout << "�븮" << endl;
			break;

		case ns::MANAGER:
			cout << "������" << endl;
			break;

		default:
			cout << "����" << endl;
			break;
		}

		cout << endl;
	}
}