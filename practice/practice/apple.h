#pragma once

namespace My_NameSpace
{
	class APPLE
	{
	private:
		int m_iNumber;
		int m_iPrice;
	public:
		void Init(int num, int price);
		int GetNum(void) const;
		int GetPrice(void) const;
		void SetNum(int num);
		void SetPrice(int price);
	};
}