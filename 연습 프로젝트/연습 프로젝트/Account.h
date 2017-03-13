#pragma once

#include "Common.h"

namespace My_NameSpace
{
	class ACCOUNT : public COMMON
	{
	public:
		ACCOUNT(void);
		ACCOUNT(int id, const char* name, int cash);
		ACCOUNT(const ACCOUNT &origin);
		
		//대입 연산자(Assignment operator)
		ACCOUNT& operator=(const ACCOUNT &ref);

		virtual ~ACCOUNT(void);
	private:
		int id;
		char* name;
		int cash;
	public:
		int GetID(void) const;
		const char* GetName(void) const;
		int GetCash(void) const;
		void SetCash(int amount);
		virtual void Deposit(int amount) = 0;
		virtual void Withdraw(int amount) = 0;
		virtual void ShowInfo(void) = 0;
		virtual ACCOUNT* MakeSelfCopiedObj(void) = 0;
	};
}