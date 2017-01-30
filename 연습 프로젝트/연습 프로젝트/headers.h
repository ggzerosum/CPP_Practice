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
	void fnc_deposit(LIST* = NULL);
	void fnc_withdraw(LIST* = NULL);
	void fnc_total(LIST* = NULL, int = 0);

	void fnc_flush(void);
}

#endif