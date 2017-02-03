#include <iostream>
#include <cstdlib>
#include <cstring>
#include "headers.h"

namespace hana_bank
{
	void bank::Init(void)
	{
		m_iSize = 0;
		m_List = NULL;
	}

	void bank::CreateList(void)
	{
		using std::cout;
		using std::endl;
		using std::cin;

		int iInput_id;
		int iInput_cash;
		char sInput_name[48] = { 0 };
		size_t temp_size;
		LIST* pTemp;

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
			//0�� 1 ���� ũ��� ���� �Ҵ�
			m_iSize++;
			m_List = new LIST;

			//�̸� �ؽ�Ʈ ũ�⸸ŭ �����Ҵ�
			temp_size = strlen(sInput_name) + 1;
			m_List->name = new char[temp_size];

			//�̸��� �����Ҵ� ������ �ؽ�Ʈ ����
			strcpy_s(m_List->name, temp_size, sInput_name);

			//����, �ܾ� �� ����
			m_List->id = iInput_id;
			m_List->cash = iInput_cash;
		}
		else
		{
			//������ 1 ������ ũ��� ���� �Ҵ�
			pTemp = new LIST[m_iSize + 1];

			//�ű� ����ü�� ���� ����ü�� �� ����
			for (int i = 0; i < m_iSize; i++)
			{
				pTemp[i] = m_List[i];
			}

			//�ű� ����ü �迭�� ������ ��� ����
			//---�̸�
			temp_size = strlen(sInput_name) + 1;
			pTemp[m_iSize].name = new char[temp_size];
			strcpy_s(pTemp[m_iSize].name, temp_size, sInput_name);

			//---���� �� �ܾ�
			pTemp[m_iSize].id = iInput_id;
			pTemp[m_iSize].cash = iInput_cash;

			//���� ���� �Ҵ� ����
			delete[] m_List;

			//�ּҰ� ����, ũ�� ����
			m_List = pTemp;
			++m_iSize;
		}
	}

	void bank::Deposit(void)
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
			if (m_List[i].id == iInput_id)
			{
				m_List[i].cash += iInput_cash;
				cout << endl << "�Ա��� �Ϸ�Ǿ����ϴ�.";
				cout << endl << "���� �ܾ�: " << m_List[i].cash;
				cout << endl;
				return;
			}
		}

		cout << endl << "��ȿ���� ���� ID�Դϴ�." << endl;
	}

	void bank::Withdraw(void)
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
			if (m_List[i].id == iInput_id)
			{
				if (m_List[i].cash < iInput_cash)
				{
					cout << endl << "������ �ܾ׺��� ū �׼��� ����� �� �����ϴ�." << endl;
					cout << "���� �ܾ�: " << m_List[i].cash << endl;
					return;
				}

				m_List[i].cash -= iInput_cash;
				cout << endl << "���� ���� �ܾ�: " << m_List[i].cash << "��" << endl;
				return;
			}
		}

		cout << endl << "��ȿ���� ���� ID�Դϴ�" << endl;
	}

	void bank::ShowList(void)
	{
		using std::cout;
		using std::endl;

		for (int i = 0; i < m_iSize; i++)
		{
			cout << (i + 1) << "��° ��" << endl
				<< "�̸�: " << m_List[i].name << endl
				<< "����: " << m_List[i].id << endl
				<< "�ܾ�: " << m_List[i].cash << endl << endl;
		}
	}

	void bank::DeleteList(void)
	{
		for (int i = 0; i < m_iSize; i++)
		{
			delete[] m_List[i].name;
		}

		delete m_List;
	}

	void fnc_flush(void)
	{
		int chr;
		while (((chr = getchar()) != '\n') && (chr != EOF));
	}
}

