#include "headers.h"
#include "Account.h"

namespace My_NameSpace
{
	ACCOUNT::ACCOUNT(void)
		:id(0), name(), cash(0)
	{}

	ACCOUNT::ACCOUNT(int id, const char* name, int cash)
		:id(id), name(name), cash(cash)
	{
	}

	ACCOUNT::ACCOUNT(const ACCOUNT &origin)
		:id(origin.id), name(origin.name), cash(origin.cash)
	{
	}

	//대입 연산자
	ACCOUNT& ACCOUNT::operator=(const ACCOUNT &ref)
	{
		id = ref.id;
		name = ref.name;
		cash = ref.cash;
		return *this;
	}

	ACCOUNT::~ACCOUNT(void)
	{
	}

	int ACCOUNT::GetID(void) const
	{
		return id;
	}

	String ACCOUNT::GetName(void) const
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