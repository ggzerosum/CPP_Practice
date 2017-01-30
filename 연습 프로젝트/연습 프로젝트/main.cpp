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
			<< "1. 계좌 개설\n"
			<< "2. 입금\n"
			<< "3. 출금\n"
			<< "4. 전체 계좌 조회\n"
			<< "5. 종료\n"
			<< "====================\n";

		cout << "선택: ";
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

	//힙 영역 전체 해제.
	//세부 이름 영역도 해제해야 함.
}