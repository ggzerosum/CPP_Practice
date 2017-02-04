#pragma once

namespace providence_hanseungmin_2017_02_03
{
	class Calculator
	{
	private:
		int count_add;
		int count_min;
		int count_multi;
		int count_div;
	public:
		int add(int, int);
		int min(int, int);
		int multi(int, int);
		int div(int, int);
		void Initialize(void);
		void ShowCount(void);
	};
}