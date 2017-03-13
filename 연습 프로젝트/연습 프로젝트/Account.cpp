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

	//대입 연산자
	ACCOUNT& ACCOUNT::operator=(const ACCOUNT &ref)
	{
		//기존 이름 삭제
		delete[] name;

		//깊은 복사
		//이름
		StrToDes(name, ref.name);
		//기타
		id = ref.id;
		cash = ref.cash;

		return *this;
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