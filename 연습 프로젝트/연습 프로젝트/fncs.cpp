#include <iostream>
#include <cstdlib>
#include <cstring>
#include "headers.h"

void hana_bank::fnc_create(LIST** ppList, int* pSize)
{
	using std::cout;
	using std::endl;
	using std::cin;

	int iInput_id;
	int iInput_cash;
	char sInput_name[48] = {0};
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

	if (*ppList == NULL)
	{
		//0�� 1 ���� ũ��� ���� �Ҵ�
		(*pSize)++;
		temp_size = sizeof(LIST)*(*pSize);
		*ppList = (LIST*)malloc(temp_size);

		//�̸� �ؽ�Ʈ ũ�⸸ŭ �����Ҵ�
		temp_size = sizeof(char)*(strlen(sInput_name) + 1);
		(*ppList)->name = (char*)malloc(temp_size);
		
		//�̸��� �����Ҵ� ������ �ؽ�Ʈ ����
		strcpy_s((*ppList)->name, temp_size, sInput_name);
		
		//����, �ܾ� �� ����
		(*ppList)->id = iInput_id;
		(*ppList)->cash = iInput_cash;
	}
	else
	{
		//������ 1 ������ ũ��� ���� �Ҵ�
		temp_size = sizeof(LIST)*(*pSize + 1);
		pTemp = (LIST*)malloc(temp_size);

		//�ű� ����ü�� ���� ����ü�� �� ����
		for (int i = 0; i < (*pSize); i++)
		{
			pTemp[i] = (*ppList)[i];
		}

		//�ű� ����ü �迭�� ������ ��� ����
		//---�̸�
		temp_size = sizeof(char)*(strlen(sInput_name) + 1);
		pTemp[*pSize].name = (char*)malloc(temp_size);
		strcpy_s(pTemp[*pSize].name, temp_size, sInput_name);

		//---���� �� �ܾ�
		pTemp[*pSize].id = iInput_id;
		pTemp[*pSize].cash = iInput_cash;

		//���� ���� �Ҵ� ����
		free(*ppList);
		
		//�ּҰ� ����, ũ�� ����
		*ppList = pTemp;
		++(*pSize);
	}
}

void hana_bank::fnc_deposit(LIST*)
{

}

void hana_bank::fnc_withdraw(LIST*)
{

}

void hana_bank::fnc_total(LIST* pList, int iSize)
{
	using std::cout;
	using std::endl;

	for (int i = 0; i < iSize; i++)
	{
		cout << (i + 1) << "��° ��" << endl
			<< "�̸�: " << pList[i].name << endl
			<< "����: " << pList[i].id << endl
			<< "�ܾ�: " << pList[i].cash << endl << endl;		
	}
}

void hana_bank::fnc_flush(void)
{
	int chr;
	while (((chr = getchar()) != '\n') && (chr != EOF));
}