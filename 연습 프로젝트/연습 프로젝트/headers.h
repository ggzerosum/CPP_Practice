#ifndef CHECK_HEADER

#define CHECK_HEADER

namespace hana_bank
{
	typedef struct account_list
	{
		int id;
		char* name;
		int cash;
	}LIST;

	void fnc_create(LIST** = NULL, int* = NULL);
	void fnc_deposit(LIST* = NULL, const int = 0);
	void fnc_withdraw(LIST* = NULL, const int = 0);
	void fnc_total(LIST* = NULL, const int = 0);

	void fnc_flush(void);
}

#endif