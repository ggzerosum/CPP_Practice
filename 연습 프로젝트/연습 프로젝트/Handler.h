#pragma once

namespace My_NameSpace
{
	class HANDLER : public COMMON
	{
	private:
		static HANDLER* ptr;
	public:
		HANDLER();
		~HANDLER();
	public:
		void AddAccountToList(BANK &ref);
		void Deposit(BANK &ref);
		void Withdraw(BANK &ref);
		void ShowInfo(BANK &ref);
		static HANDLER* itSelf(void);
	};
}