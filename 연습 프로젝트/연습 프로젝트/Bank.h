#pragma once
#include "Account.h"
#include "SmartArr.h"

namespace My_NameSpace
{
	namespace ns = My_EnumSpace;

	class BANK : public COMMON
	{
	private:
		static BANK* ptr;
		SmartArr<ACCOUNT> m_List;
		int m_iSize;

		//복사 생성자 금지
		BANK(const BANK &original);
		//대입 연산자 금지
		void operator=(const BANK &origin);

	public:
		//생성자
		BANK(void);
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