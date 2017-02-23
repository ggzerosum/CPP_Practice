#pragma once
#include "Account.h"

namespace My_NameSpace
{
	class NormalAccount : public ACCOUNT
	{
	public:
		NormalAccount();
		NormalAccount(int id, const char* name, int cash, int interest);
		NormalAccount(const NormalAccount &origin);
		virtual ~NormalAccount();

	private:
		int interest;

	public:
		void SetInterest(int amount);
		int GetInterest(void);
		virtual void Deposit(int amount);
		virtual void Withdraw(int amount);
		virtual void ShowInfo(void);
		virtual ACCOUNT* MakeSelfCopiedObj(void);
	};
}