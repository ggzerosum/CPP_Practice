#include "headers.h"

using namespace std;
namespace err = My_EnumSpace;

namespace My_NameSpace
{
	HANDLER* HANDLER::ptr = NULL;

	HANDLER::HANDLER()
	{
	}

	HANDLER::~HANDLER()
	{
		HANDLER::ptr = NULL;
	}

	void HANDLER::AddAccountToList(BANK &ref)
	{
		int id;
		int cash;
		char name[48] = { 0 };

		cout << endl << "1. 개설할 계좌번호(\'-\'없는 숫자)" << endl << ": ";
		fnc_flush();
		cin >> id;

		cout << endl << "2. 계좌의 이름" << endl << ": ";
		fnc_flush();
		cin >> name;

		cout << endl << "3. 계좌 시작 금액" << endl << ": ";
		fnc_flush();
		cin >> cash;

		ref.CreateList(id, name, cash);
	}

	void HANDLER::Deposit(BANK &ref)
	{
		int id, cash, error_code;

		cout << "1. 입금할 계좌번호" << endl << ": ";
		fnc_flush();
		cin >> id;

		cout << endl << "2. 입금할 금액" << endl << ": ";
		fnc_flush();
		cin >> cash;

		error_code = ref.Deposit(id, cash);

		switch (error_code)
		{
		case err::SUCCESS:
			cout << endl << "입금이 완료되었습니다.";
			cout << endl << "현재 잔액: " << ref.GetCashOfAccount(id) << endl;
			break;

		default:
			cout << endl << "유효하지 않은 ID입니다." << endl;
			break;
		}
	}

	void HANDLER::Withdraw(BANK &ref)
	{
		int id, cash, error_code;

		cout << "1. 출금할 계좌번호" << endl << ": ";
		fnc_flush();
		cin >> id;

		cout << endl << "2. 출금할 금액" << endl << ": ";
		fnc_flush();
		cin >> cash;

		error_code = ref.Withdraw(id, cash);

		switch (error_code)
		{
		case err::SUCCESS:
			cout << endl << "현재 계좌 잔액: " << ref.GetCashOfAccount(id) << "원" << endl;
			break;

		case err::ID:
			cout << endl << "유효하지 않은 ID입니다" << endl;
			break;

		case err::CASH:
			cout << endl << "계좌의 잔액보다 큰 액수는 출금할 수 없습니다." << endl;
			cout << "현재 잔액: " << ref.GetCashOfAccount(id) << endl;
			break;
		}
	}

	void HANDLER::ShowInfo(BANK &ref)
	{
		ref.ShowList();
	}

	HANDLER* HANDLER::itSelf(void)
	{
		if (HANDLER::ptr == NULL)
		{
			HANDLER::ptr = new HANDLER;
		}

		return HANDLER::ptr;
	}
}