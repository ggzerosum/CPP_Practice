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

		cout << endl << "�Ա��� �Ϸ�Ǿ����ϴ�.";
		cout << endl << "���� �ܾ�: " << GetCash() << endl;
	}

	void NormalAccount::Withdraw(int amount)
	{
		int cash = GetCash() - amount;

		if (cash < 0)
		{
			cout << endl << "������ �ܾ׺��� ū �׼��� ����� �� �����ϴ�." << endl;
			cout << "���� �ܾ�: " << GetCash() << endl;
			return;
		}

		SetCash(cash);
		cout << endl << "���� ���� �ܾ�: " << GetCash() << "��" << endl;
		return;
	}

	void NormalAccount::ShowInfo(void)
	{
		cout << "ID: " << GetID() << endl;
		cout << "�̸�: " << GetName() << endl;
		cout << "�ܾ�: " << GetCash() << endl;
		cout << "������: " << interest << endl;
	}

	ACCOUNT* NormalAccount::MakeSelfCopiedObj(void)
	{
		return new NormalAccount(*this);
	}
}