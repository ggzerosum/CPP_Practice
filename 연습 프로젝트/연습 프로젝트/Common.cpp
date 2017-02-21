#include "headers.h"

namespace My_NameSpace
{
	void COMMON::fnc_flush(void)
	{
		int chr;
		while (((chr = getchar()) != '\n') && (chr != EOF));
	}
}