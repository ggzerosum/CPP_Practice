#pragma once
#include "Account.h"

namespace My_NameSpace
{
	class HighCreditAccount : public ACCOUNT
	{
	public:
		HighCreditAccount();
		HighCreditAccount(int id, const char* name, int cash, int interest, int grade);
		HighCreditAccount(const HighCreditAccount &origin);
		virtual ~HighCreditAccount();

	private:
		int interest;
		int grade;
	
	public:
		void SetInterest(int amount);
		int GetInterest(void);
		void SetGrade(int grade);
		int GetGrade(void);
		virtual void Deposit(int amount);
		virtual void Withdraw(int amount);
		virtual void ShowInfo(void);
		virtual ACCOUNT* MakeSelfCopiedObj(void);
	};
}