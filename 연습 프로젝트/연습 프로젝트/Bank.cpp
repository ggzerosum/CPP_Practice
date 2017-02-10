#include "headers.h"

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

	void BANK::CreateList(void)
	{
		using std::cout;
		using std::endl;
		using std::cin;

		int iInput_id;
		int iInput_cash;
		char sInput_name[48] = { 0 };
		ACCOUNT** pTemp;

		cout << endl << "1. ������ ���¹�ȣ(\'-\'���� ����)" << endl << ": ";
		fnc_flush();
		cin >> iInput_id;

		cout << endl << "2. ������ �̸�" << endl << ": ";
		fnc_flush();
		cin >> sInput_name;

		cout << endl << "3. ���� ���� �ݾ�" << endl << ": ";
		fnc_flush();
		cin >> iInput_cash;

		if (m_List == NULL)
		{
			//0�� 1 ���� ũ��� ���� �Ҵ�(��ü ������ ����)
			++m_iSize;
			m_List = new ACCOUNT*[m_iSize];
			
			//�� ��ü ���� �� ������ ������ �ּҰ� ����
			*m_List = new ACCOUNT(iInput_id, sInput_name, iInput_cash);
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
			pTemp[m_iSize] = new ACCOUNT(iInput_id, sInput_name, iInput_cash);

			//���� ���� �Ҵ� ����
			delete[] m_List;

			//�ּҰ� ����, ũ�� ����
			m_List = pTemp;
			++m_iSize;
		}
	}

	void BANK::Deposit(void)
	{
		using std::cout;
		using std::cin;
		using std::endl;

		int iInput_id, iInput_cash;

		cout << "1. �Ա��� ���¹�ȣ" << endl << ": ";
		cin >> iInput_id;

		cout << endl << "2. �Ա��� �ݾ�" << endl << ": ";
		cin >> iInput_cash;

		for (int i = 0; i < m_iSize; i++)
		{
			if (m_List[i]->GetID() == iInput_id)
			{
				m_List[i]->AddCash(iInput_cash);
				cout << endl << "�Ա��� �Ϸ�Ǿ����ϴ�.";
				cout << endl << "���� �ܾ�: " << m_List[i]->GetCash();
				cout << endl;
				return;
			}
		}

		cout << endl << "��ȿ���� ���� ID�Դϴ�." << endl;
	}

	void BANK::Withdraw(void)
	{
		using std::cout;
		using std::cin;
		using std::endl;

		int iInput_id, iInput_cash;

		cout << "1. ����� ���¹�ȣ" << endl << ": ";
		cin >> iInput_id;

		cout << endl << "2. ����� �ݾ�" << endl << ": ";
		cin >> iInput_cash;

		for (int i = 0; i < m_iSize; i++)
		{
			if (m_List[i]->GetID() == iInput_id)
			{
				
				if (m_List[i]->MinusCash(iInput_cash))
				{
					cout << endl << "���� ���� �ܾ�: " << m_List[i]->GetCash() << "��" << endl;
					return;
				}

				cout << endl << "������ �ܾ׺��� ū �׼��� ����� �� �����ϴ�." << endl;
				cout << "���� �ܾ�: " << m_List[i]->GetCash() << endl;
				return;
			}
		}

		cout << endl << "��ȿ���� ���� ID�Դϴ�" << endl;
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

	void BANK::fnc_flush(void)
	{
		int chr;
		while (((chr = getchar()) != '\n') && (chr != EOF));
	}
}