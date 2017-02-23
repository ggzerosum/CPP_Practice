#include "headers.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "Bank.h"

namespace My_NameSpace
{
	BANK* BANK::ptr = nullptr;

	//������
	BANK::BANK(void)
		:m_iSize(0), m_List(nullptr)
	{
		//empty
	}

	//���� ������
	BANK::BANK(const BANK &original)
		:m_iSize(original.m_iSize)
	{
		m_List = new ACCOUNT*[m_iSize];

		for (int i = 0; i < m_iSize; i++)
		{
			m_List[i] = original.m_List[i]->MakeSelfCopiedObj();
		}
	}

	//�Ҹ���
	BANK::~BANK(void)
	{
		for (int i = 0; i < m_iSize; i++)
		{
			delete m_List[i];
		}

		delete[] m_List;
	}


	void BANK::ShowMenu(void)
	{
		cout	<< "\n====================\n"
				<< "1. ���� ����\n"
				<< "2. �Ա�\n"
				<< "3. ���\n"
				<< "4. ��ü ���� ��ȸ\n"
				<< "5. ����\n"
				<< "====================\n";
	}

	void BANK::CreateList(void)
	{
		namespace ES = My_EnumSpace;

		int check;
		ACCOUNT* ptr;
		ACCOUNT** pTemp;

		cout << endl << "0. � ���¸� �����Ͻðڽ��ϱ�?";
		cout << endl << "(1��: ���� ����, 2��: ��� ����)" << endl << ": ";
		fnc_flush();
		cin >> check;

		//�� ��ü ����
		switch (check)
		{
		case ES::NORMAL:
			ptr = MakeNormalAccountObj();
			break;
			
		default:
			ptr = MakeHighCreditAccountObj();
			break;
		}

		if (m_List == nullptr)
		{
			//0�� 1 ���� ũ��� ���� �Ҵ�(��ü ������ ����)
			m_iSize++;
			m_List = new ACCOUNT*[m_iSize];
			
			//������ ������ �� ��ü �ּҰ� ����
			*m_List = ptr;
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
			pTemp[m_iSize] = ptr;

			//���� ���� �Ҵ� ����
			delete[] m_List;

			//�ּҰ� ����, ũ�� ����
			m_List = pTemp;
			m_iSize++;
		}
	}

	void BANK::Deposit(void)
	{
		int id, cash;

		cout << "1. �Ա��� ���¹�ȣ" << endl << ": ";
		fnc_flush();
		cin >> id;

		cout << endl << "2. �Ա��� �ݾ�" << endl << ": ";
		fnc_flush();
		cin >> cash;

		for (int i = 0; i < m_iSize; i++)
		{
			if (m_List[i]->GetID() == id)
			{
				m_List[i]->Deposit(cash);
				return;
			}
		}

		cout << endl << "��ȿ���� ���� ID�Դϴ�." << endl;
	}

	void BANK::Withdraw(void)
	{
		int id, cash;

		cout << "1. ����� ���¹�ȣ" << endl << ": ";
		fnc_flush();
		cin >> id;

		cout << endl << "2. ����� �ݾ�" << endl << ": ";
		fnc_flush();
		cin >> cash;

		for (int i = 0; i < m_iSize; i++)
		{
			if (m_List[i]->GetID() == id)
			{
				m_List[i]->Withdraw(cash);
				return;
			}
		}

		cout << endl << "��ȿ���� ���� ID�Դϴ�." << endl;
	}

	void BANK::ShowList(void)
	{
		for (int i = 0; i < m_iSize; i++)
		{
			cout << "<" << (i + 1) << "��° ��>" << endl;
			m_List[i]->ShowInfo();
			cout << endl;
		}
	}

	ACCOUNT* BANK::MakeNormalAccountObj(void)
	{
		int id, cash, interest;
		char name[48] = { 0 };

		cout << endl << "1. ������ ���¹�ȣ(\'-\'���� ����)" << endl << ": ";
		fnc_flush();
		cin >> id;

		cout << endl << "2. ������ �̸�" << endl << ": ";
		fnc_flush();
		cin >> name;

		cout << endl << "3. ���� ���� �ݾ�" << endl << ": ";
		fnc_flush();
		cin >> cash;

		cout << endl << "4. �⺻ ������" << endl << ": ";
		fnc_flush();
		cin >> interest;

		return new NormalAccount(id, name, cash, interest);
	}


	ACCOUNT* BANK::MakeHighCreditAccountObj(void)
	{
		int id, cash, interest, grade;
		char name[48] = { 0 };

		cout << endl << "1. ������ ���¹�ȣ(\'-\'���� ����)" << endl << ": ";
		fnc_flush();
		cin >> id;

		cout << endl << "2. ������ �̸�" << endl << ": ";
		fnc_flush();
		cin >> name;

		cout << endl << "3. ���� ���� �ݾ�" << endl << ": ";
		fnc_flush();
		cin >> cash;

		cout << endl << "4. �⺻ ������" << endl << ": ";
		fnc_flush();
		cin >> interest;

		cout << endl << "5. ���(1=>A, 2=>B, 3=>C)" << endl << ": ";
		fnc_flush();
		cin >> grade;

		return new HighCreditAccount(id, name, cash, interest, grade);
	}


	BANK* BANK::itSelf(void)
	{
		if (!BANK::ptr)
		{
			BANK::ptr = new BANK;
		}

		return BANK::ptr;
	}
}