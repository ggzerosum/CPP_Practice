#include "includes.h"

namespace My_NameSpace
{
	APPLE::APPLE(int num, int price)
		:m_iNumber(num), m_iPrice(price)
	{
		//empty
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

	/*
	void APPLE::SetPrice(int price)
	{
		m_iPrice = price;
	}
	*/
}