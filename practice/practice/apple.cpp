#include "includes.h"

namespace My_NameSpace
{
	void APPLE::Init(int num, int price)
	{
		if (num < 0) num = 0;
		if (price < 0) price = 0;

		m_iNumber = num;
		m_iPrice = price;
	}

	int APPLE::GetNum(void) const
	{
		return m_iNumber;
	}

	int APPLE::GetPrice(void) const
	{
		return m_iPrice;
	}

	void APPLE::SetNum(int num)
	{
		m_iNumber = num;
	}

	void APPLE::SetPrice(int price)
	{
		m_iPrice = price;
	}
}