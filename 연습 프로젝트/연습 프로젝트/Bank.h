#pragma once
#include "Account.h"

namespace My_NameSpace
{
	namespace ns = My_EnumSpace;

	class BANK : public COMMON
	{
	private:
		static BANK* ptr;
		int m_iSize;
		ACCOUNT** m_List;

	public:
		//생성자
		BANK(void);
		//복사 생성자
		BANK(const BANK &original);
		//소멸자
		~BANK(void);

	public:
		void ShowMenu(void);
		void CreateList(void);
		void Deposit(void);
		void Withdraw(void);
		void ShowList(void);
		static BANK* itSelf(void);

	protected:
		ACCOUNT* MakeNormalAccountObj(void);
		ACCOUNT* MakeHighCreditAccountObj(void);
	};
}