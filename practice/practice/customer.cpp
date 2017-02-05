#include "includes.h"

namespace My_NameSpace
{
	CUSTOMER::CUSTOMER(int money)
		:m_iMoney(money), m_cApples(0, PriceOfApples)
	{
		//m_iMoney = money;
	}

	void CUSTOMER::BuyApples(SELLER &seller, int num)
	{
		int CurNum = m_cApples.GetNum();
		int price = m_cApples.GetPrice();
		int payment = num * price;

		if (payment > m_iMoney)
		{
			cout << "���� �������� �����մϴ�." << endl;
			return;
		}

		if (seller.SaleApples(num))
		{
			m_cApples.SetNum(CurNum + num);
			m_iMoney -= payment;
			cout << "�ŷ��� ���������� ���ƽ��ϴ�." << endl;
		}
	}

	void CUSTOMER::ShowState(void) const
	{
		cout << "<�� ��Ȳ>" << endl;
		cout << "��� ����: " << m_cApples.GetNum() << endl;
		cout << "������: " << m_iMoney << endl;
	}
}