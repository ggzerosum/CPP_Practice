#pragma once

namespace providence_hanseungmin_2017_02_03
{
	class Printer
	{
	private:
		char* ptr;
	public:
		void Init(void);
		void SetString(const char* text);
		void ShowString(void);
	};
}