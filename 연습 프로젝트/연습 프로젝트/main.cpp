#include "headers.h"

void main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;
	using namespace hana_bank;

	int iInput;
	bool key = true;

	//BANK* ptr = new BANK;
	//BANK &HansBank = *ptr;

	BANK HansBank;

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
			HansBank.CreateList();
			break;

		case deposit:
			HansBank.Deposit();
			break;

		case withdraw:
			HansBank.Withdraw();
			break;

		case total:
			HansBank.ShowList();
			break;

		default:
			key = false;
			break;
		}
	}

	//���� ���� ����
	BANK AnotherBank = HansBank;

	//Ŭ���� ��ü ����(delete�� �������� ������ ����� Ű����. �ٸ� ������ ������.)
	//delete &AnotherBank;
	//delete &HansBank;
}