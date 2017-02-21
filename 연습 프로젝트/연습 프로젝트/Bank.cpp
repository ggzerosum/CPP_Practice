#include "headers.h"

namespace err = My_EnumSpace;

namespace My_NameSpace
{
	//������
	BANK::BANK(void)
		:m_iSize(0), m_List(NULL)
	{
		//empty
	}

	//���� ������
	BANK::BANK(const BANK &original)
		:m_iSize(original.m_iSize)
	{
		ACCOUNT** origin = original.m_List;
		m_List = new ACCOUNT*[m_iSize];

		for (int i = 0; i < m_iSize; ++i)
		{
			m_List[i] = new ACCOUNT(*(origin[i]));
		}
	}

	//�Ҹ���
	BANK::~BANK(void)
	{
		for (int i = 0; i < m_iSize; ++i)
		{
			delete m_List[i];
		}

		delete[] m_List;
	}

	void BANK::CreateList(int id, const char* name, int cash)
	{
		ACCOUNT** pTemp;

		if (m_List == NULL)
		{
			//0�� 1 ���� ũ��� ���� �Ҵ�(��ü ������ ����)
			++m_iSize;
			m_List = new ACCOUNT*[m_iSize];
			
			//�� ��ü ���� �� ������ ������ �ּҰ� ����
			*m_List = new ACCOUNT(id, name, cash);
		}
		else
		{
			//������ 1 ������ ũ��� ���� �Ҵ�
			pTemp = new ACCOUNT*[m_iSize + 1];

			//�ű� ������ �迭�� ���� �迭�� �� ����
			for (int i = 0; i < m_iSize; i++)
			{
				pTemp[i] = m_List[i];
			}

			//�ű� ������ �迭�� ������ ��� ����
			pTemp[m_iSize] = new ACCOUNT(id, name, cash);

			//���� ���� �Ҵ� ����
			delete[] m_List;

			//�ּҰ� ����, ũ�� ����
			m_List = pTemp;
			++m_iSize;
		}
	}

	int BANK::Deposit(int id, int cash)
	{
		for (int i = 0; i < m_iSize; i++)
		{
			if (m_List[i]->GetID() == id)
			{
				m_List[i]->AddCash(cash);
				return err::SUCCESS;
			}
		}

		return err::ID;
	}

	int BANK::Withdraw(int id, int cash)
	{
		for (int i = 0; i < m_iSize; i++)
		{
			if (m_List[i]->GetID() == id)
			{
				if (m_List[i]->MinusCash(cash))
					return err::SUCCESS;
				else
					return err::CASH;
			}
		}

		return err::ID;
	}

	void BANK::ShowList(void)
	{
		using std::cout;
		using std::endl;

		for (int i = 0; i < m_iSize; i++)
		{
			cout << "<" << (i + 1) << "��° ��>" << endl
				<< "�̸�: " << m_List[i]->GetName() << endl
				<< "����: " << m_List[i]->GetID() << endl
				<< "�ܾ�: " << m_List[i]->GetCash() << endl << endl;
		}
	}

	int BANK::GetCashOfAccount(int id)
	{
		for (int i = 0; i < m_iSize; i++)
		{
			if (m_List[i]->GetID() == id)
				return m_List[i]->GetCash();
		}

		return 0;
	}
}