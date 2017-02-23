#include "headers.h"
#include "Classes.h"

using namespace hana_bank;

enum
{
	create = 1,
	deposit = 2,
	withdraw = 3,
	total = 4,
	close = 5
};

void main(void)
{
	int iInput;
	bool key = true;

	while (key)
	{
		BANK::itSelf()->ShowMenu();
		cout << "선택: ";
		cin >> iInput;

		system("cls");

		switch (iInput)
		{
		case create:
			BANK::itSelf()->CreateList();
			break;

		case deposit:
			BANK::itSelf()->Deposit();
			break;

		case withdraw:
			BANK::itSelf()->Withdraw();
			break;

		case total:
			BANK::itSelf()->ShowList();
			break;

		default:
			key = false;
			break;
		}
	}

	//클래스 객체 해제(delete는 힙영역의 공간을 지우는 키워드. 다른 영역에 못쓴다.)
	delete BANK::itSelf();
}