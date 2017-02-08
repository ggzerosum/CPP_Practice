#pragma once

namespace My_NameSpace
{
	class bank
	{
	private:
		int m_iSize;
		ACCOUNT** m_List;
		void fnc_flush(void);
	public:
		bank(void);
		~bank(void);

		void CreateList(void);
		void Deposit(void);
		void Withdraw(void);
		void ShowList(void);
	};
}