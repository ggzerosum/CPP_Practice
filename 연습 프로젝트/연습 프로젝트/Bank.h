#pragma once

namespace My_NameSpace
{
	class BANK
	{
	private:
		int m_iSize;
		ACCOUNT** m_List;
		void fnc_flush(void);
	public:
		//생성자
		BANK(void);
		//복사 생성자
		BANK(const BANK &original);
		//소멸자
		~BANK(void);

		void CreateList(void);
		void Deposit(void);
		void Withdraw(void);
		void ShowList(void);
	};
}