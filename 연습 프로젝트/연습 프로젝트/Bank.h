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
		//������
		BANK(void);
		//���� ������
		BANK(const BANK &original);
		//�Ҹ���
		~BANK(void);

		void CreateList(void);
		void Deposit(void);
		void Withdraw(void);
		void ShowList(void);
	};
}