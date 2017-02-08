#include "headers.h"

namespace My_NameSpace
{
	ACCOUNT::ACCOUNT(void)
		:id(0), name(NULL), cash(0)
	{
		//empty
	}

	ACCOUNT::ACCOUNT(int id, char* name, int cash)
		:id(id), name(name), cash(cash)
	{
		//empty
	}

	ACCOUNT::~ACCOUNT(void)
	{
		if (name != NULL)
		{
			delete[] name;
		}
	}

	int ACCOUNT::GetID(void)
	{
		return id;
	}

	char* ACCOUNT::GetName(void)
	{
		return name;
	}

	int ACCOUNT::GetCash(void)
	{
		return cash;
	}

	void ACCOUNT::AddCash(int money)
	{
		this->cash += money;
	}

	bool ACCOUNT::MinusCash(int money)
	{
		if (this->cash < money)
			return false;

		this->cash -= money;
		return true;
	}
}