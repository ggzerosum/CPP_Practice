#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "headers.h"

void main(void)
{
	using std::cout;
	using std::cin;
	using namespace hana_bank;

	int iInput;
	LIST* pList = NULL;
	int iSize = 0;
	int key = 1;

	enum
	{
		create = 1,
		deposit = 2,
		withdraw = 3,
		total = 4,
		close = 5
	};

	while (key)
	{
		cout << "\n====================\n"
			<< "1. ���� ����\n"
			<< "2. �Ա�\n"
			<< "3. ���\n"
			<< "4. ��ü ���� ��ȸ\n"
			<< "5. ����\n"
			<< "====================\n";

		cout << "����: ";
		cin >> iInput;

		system("cls");

		switch (iInput)
		{
		case create:
			fnc_create(&pList, &iSize);
			break;

		case deposit:
			break;

		case withdraw:
			break;

		case total:
			fnc_total(pList, iSize);
			break;

		default:
			key = 0;
			break;
		}
	}

	//�� ���� ��ü ����.
	//���� �̸� ������ �����ؾ� ��.
}