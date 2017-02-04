#include "includes.h"

namespace providence_hanseungmin_2017_02_03
{
	int Calculator::add(int a, int b)
	{
		count_add++;
		return (a + b);
	}

	int Calculator::min(int a, int b)
	{
		count_min++;
		return (a - b);
	}

	int Calculator::multi(int a, int b)
	{
		count_multi++;
		return (a * b);
	}

	int Calculator::div(int a, int b)
	{
		count_div++;
		return (a / b);
	}

	void Calculator::ShowCount(void)
	{
		cout << "µ¡¼À È½¼ö: " << count_add << endl;
		cout << "»¬¼À È½¼ö: " << count_min << endl;
		cout << "°ö¼À È½¼ö: " << count_multi << endl;
		cout << "³ª´°¼À È½¼ö: " << count_div << endl;
	}

	void Calculator::Initialize(void)
	{
		count_add = 0;
		count_min = 0;
		count_multi = 0;
		count_div = 0;
	}
}