#pragma once

namespace My_NameSpace
{
	class SELLER
	{
	private:
		APPLE m_cApples;
		int m_iMoney;
	public:
		void Init(void);
		bool SaleApples(int num);
		void ShowState(void) const;
	};
}