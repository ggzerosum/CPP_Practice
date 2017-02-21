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

	//Ŭ���� ��ü ����(delete�� �������� ������ ����� Ű����. �ٸ� ������ ������.)
	delete ptr;
	delete HANDLER::itSelf();
}