#pragma once

namespace My_NameSpace
{
	class SELLER
	{
	private:
		APPLE m_cApples;
		int m_iMoney;
	public:
		SELLER(int money = Sellers_Default_Money);
		bool SaleApples(int num);
		void ShowState(void) const;
	};
}