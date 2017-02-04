#include "includes.h"

namespace providence_hanseungmin_2017_02_03
{
	void Printer::Init(void)
	{
		ptr = NULL;
	}

	void Printer::SetString(const char* text)
	{
		if (ptr != NULL)
		{
			delete[] ptr;
			ptr = NULL;
		}

		size_t size = strlen(text) + 1;
		ptr = new char[size];

		strcpy_s(ptr, size, text);
	}

	void Printer::ShowString(void)
	{
		if (ptr == NULL)
		{
			cout << "텍스트 없음" << endl;
			return;
		}

		cout << ptr << endl;
	}
}