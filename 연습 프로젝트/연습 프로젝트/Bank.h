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

		//���� ������ ����
		BANK(const BANK &original);
		//���� ������ ����
		void operator=(const BANK &origin);

	public:
		//������
		BANK(void);
		//�Ҹ���
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