#include "headers.h"
#include "Account.h"

namespace My_NameSpace
{
	ACCOUNT::ACCOUNT(void)
		:id(0), name(nullptr), cash(0)
	{}

	ACCOUNT::ACCOUNT(int id, const char* name, int cash)
		:id(id), cash(cash)
	{
		StrToDes(this->name, name);
	}

	ACCOUNT::ACCOUNT(const ACCOUNT &origin)
		:id(origin.id), cash(origin.cash)
	{
		StrToDes(name, origin.name);
	}

	ACCOUNT::~ACCOUNT(void)
	{
		if (name != nullptr)
		{
			delete[] name;
		}
	}

	int ACCOUNT::GetID(void) const
	{
		return id;
	}

	const char* ACCOUNT::GetName(void) const
	{
		return name;
	}

	int ACCOUNT::GetCash(void) const
	{
		return cash;
	}

	void ACCOUNT::SetCash(int amount)
	{
		cash = amount;
	}
}