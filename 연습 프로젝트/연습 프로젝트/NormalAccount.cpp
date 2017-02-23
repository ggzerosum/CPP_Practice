#include "headers.h"
#include "NormalAccount.h"

namespace My_NameSpace
{
	NormalAccount::NormalAccount()
		:interest(1)
	{}

	NormalAccount::NormalAccount(int id, const char* name, int cash, int interest)
		:ACCOUNT(id, name, cash), interest(interest)
	{}

	NormalAccount::NormalAccount(const NormalAccount &origin)
		:ACCOUNT(origin), interest(origin.interest)
	{}

	NormalAccount::~NormalAccount()
	{}


	void NormalAccount::SetInterest(int amount)
	{
		interest = amount;
	}

	int NormalAccount::GetInterest(void)
	{
		return interest;
	}

	void NormalAccount::Deposit(int amount)
	{
		int fee, sum;
		fee = GetCash() * (interest / 100.0);
		sum = GetCash() + fee + amount;
		SetCash(sum);

		cout << endl << "입금이 완료되었습니다.";
		cout << endl << "현재 잔액: " << GetCash() << endl;
	}

	void NormalAccount::Withdraw(int amount)
	{
		int cash = GetCash() - amount;

		if (cash < 0)
		{
			cout << endl << "계좌의 잔액보다 큰 액수는 출금할 수 없습니다." << endl;
			cout << "현재 잔액: " << GetCash() << endl;
			return;
		}

		SetCash(cash);
		cout << endl << "현재 계좌 잔액: " << GetCash() << "원" << endl;
		return;
	}

	void NormalAccount::ShowInfo(void)
	{
		cout << "ID: " << GetID() << endl;
		cout << "이름: " << GetName() << endl;
		cout << "잔액: " << GetCash() << endl;
		cout << "이자율: " << interest << endl;
	}

	ACCOUNT* NormalAccount::MakeSelfCopiedObj(void)
	{
		return new NormalAccount(*this);
	}
}