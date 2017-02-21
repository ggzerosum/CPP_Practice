#include "headers.h"

void main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;
	using namespace hana_bank;

	int iInput;
	bool key = true;

	BANK* ptr = new BANK;

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
			HANDLER::itSelf()->AddAccountToList(*ptr);
			break;

		case deposit:
			HANDLER::itSelf()->Deposit(*ptr);
			break;

		case withdraw:
			HANDLER::itSelf()->Withdraw(*ptr);
			break;

		case total:
			HANDLER::itSelf()->ShowInfo(*ptr);
			break;

		default:
			key = false;
			break;
		}
	}

	//클래스 객체 해제(delete는 힙영역의 공간을 지우는 키워드. 다른 영역에 못쓴다.)
	delete ptr;
	delete HANDLER::itSelf();
}