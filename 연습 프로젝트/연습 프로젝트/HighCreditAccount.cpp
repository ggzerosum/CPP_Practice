#include "headers.h"
#include "HighCreditAccount.h"

namespace ES = My_EnumSpace;

namespace My_NameSpace
{
	HighCreditAccount::HighCreditAccount()
		:interest(1), grade(ES::Grade_C)
	{}

	HighCreditAccount::HighCreditAccount(int id, const char* name, int cash, int interest, int grade)
		:ACCOUNT(id, name, cash), interest(interest), grade(grade)
	{}

	HighCreditAccount::HighCreditAccount(const HighCreditAccount &origin)
		:ACCOUNT(origin), interest(origin.interest), grade(origin.grade)
	{}

	HighCreditAccount::~HighCreditAccount()
	{}

	void HighCreditAccount::SetInterest(int amount)
	{
		interest = amount;
	}

	int HighCreditAccount::GetInterest(void)
	{
		return interest;
	}

	void HighCreditAccount::SetGrade(int grade)
	{
		this->grade = grade;
	}

	int HighCreditAccount::GetGrade(void)
	{
		return grade;
	}

	void HighCreditAccount::Deposit(int amount)
	{
		int bonus, sum, fee;

		switch (grade)
		{
		case ES::Grade_A:
			bonus = 7;
			break;

		case ES::Grade_B:
			bonus = 4;
			break;
		
		case ES::Grade_C:
			bonus = 2;
			break;
		}

		fee = GetCash() * ((interest + bonus) / 100.0);
		sum = GetCash() + fee + amount;
		SetCash(sum);

		cout << endl << "입금이 완료되었습니다.";
		cout << endl << "현재 잔액: " << GetCash() << endl;
	}

	void HighCreditAccount::Withdraw(int amount)
	{
		int sum = GetCash() - amount;

		if (sum < 0)
		{
			cout << endl << "계좌의 잔액보다 큰 액수는 출금할 수 없습니다." << endl;
			cout << "현재 잔액: " << GetCash() << endl;
			return;
		}

		SetCash(sum);
		cout << endl << "현재 계좌 잔액: " << GetCash() << "원" << endl;
		return;
	}

	void HighCreditAccount::ShowInfo(void)
	{
		char CharOfGrade;

		switch (grade)
		{
		case ES::Grade_A:
			CharOfGrade = 'A';
			break;

		case ES::Grade_B:
			CharOfGrade = 'B';
			break;

		case ES::Grade_C:
			CharOfGrade = 'C';
			break;
		}

		cout << "ID: " << GetID() << endl;
		cout << "이름: " << GetName() << endl;
		cout << "잔액: " << GetCash() << endl;
		cout << "이자율: " << interest << endl;
		cout << "등급: " << CharOfGrade << endl;
	}


	ACCOUNT* HighCreditAccount::MakeSelfCopiedObj(void)
	{
		return new HighCreditAccount(*this);
	}
}