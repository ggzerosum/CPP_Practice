#include "headers.h"
#include "Common.h"

namespace My_NameSpace
{
	void COMMON::fnc_flush(void)
	{
		int chr;
		while (((chr = getchar()) != '\n') && (chr != EOF));
	}

	void COMMON::StrToDes(char* &destination, const char* source)
	{
		rsize_t size = strlen(source) + 1;
		destination = new char[size];
		strcpy_s(destination, size, source);
	}
}