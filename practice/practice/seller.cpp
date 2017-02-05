#include "includes.h"

namespace My_NameSpace
{
	SELLER::SELLER(int money)
		:m_iMoney(money), m_cApples(Sellers_Init_NumOfApples, PriceOfApples) // ����� �ʱ�ȭ�� ���ÿ�.
	{
		//m_iMoney = money; //���� �� �ʱ�ȭ.
	}

	bool SELLER::SaleApples(int num)
	{
		int CurNum = m_cApples.GetNum();
		int price = m_cApples.GetPrice();
		int Profit = price * num;

		if (num > CurNum)
		{
			cout << "��� ����� ����� �����մϴ�." << endl;
			return false;
		}

		m_cApples.SetNum(CurNum - num);
		m_iMoney += Profit;

		return true;
	}

	void SELLER::ShowState(void) const
	{
		cout << "<��� ��� ��Ȳ>" << endl;
		cout << "��� ������: " << m_cApples.GetNum() << endl;
		cout << "������: " << m_iMoney << "��" << endl;
	}
}