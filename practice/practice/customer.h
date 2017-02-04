#pragma once

namespace My_NameSpace
{
	class CUSTOMER
	{
	private:
		APPLE m_cApples;
		int m_iMoney;
	public:
		void Init(void);
		void BuyApples(SELLER &seller, int num);
		void ShowState(void) const;
	};
}