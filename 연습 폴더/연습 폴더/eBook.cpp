#include "Inlcudes.h"

namespace My_NameSpace
{
	eBook::eBook(void)
		:DRMKey(NULL)
	{}

	eBook::eBook(const char* title, const char* isbn, int price, const char* key)
		:Book(title, isbn, price)
	{
		SetStrToDestination(DRMKey, key);
	}

	eBook::eBook(const eBook &copy)
		:Book(copy)
	{
		SetStrToDestination(DRMKey, copy.DRMKey);
	}

	void eBook::SetKey(const char* str)
	{
		SetStrToDestination(DRMKey, str);
	}

	const char* eBook::GetKey(void) const
	{
		return DRMKey;
	}

	void eBook::ShowEBookInfo(void) const
	{
		ShowBookInfo();
		cout << "º¸¾È: " << DRMKey << endl;
	}

	eBook::~eBook(void)
	{
		if (DRMKey != NULL)
			delete[] DRMKey;
	}
}
