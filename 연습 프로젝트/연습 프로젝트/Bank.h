#pragma once

namespace My_NameSpace
{
	namespace ns = My_EnumSpace;

	class BANK
	{
	private:
		int m_iSize;
		ACCOUNT** m_List;
	public:
		//������
		BANK(void);
		//���� ������
		BANK(const BANK &original);
		//�Ҹ���
		~BANK(void);
	public:
		void CreateList(int id, const char* name, int cash);
		int Deposit(int id, int cash);
		int Withdraw(int id, int cash);
		void ShowList(void);
		int GetCashOfAccount(int id);
	};
}