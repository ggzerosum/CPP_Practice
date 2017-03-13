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

	//대입 연산자 오버로딩
	eBook& eBook::operator=(const eBook &ref)
	{
		//동적 할당 해제
		if (DRMKey != nullptr)
			delete[] DRMKey;

		//멤버 복사
		Book::operator=(ref);
		SetStrToDestination(DRMKey, ref.DRMKey);

		return *this;
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
		cout << "보안: " << DRMKey << endl;
	}

	eBook::~eBook(void)
	{
		if (DRMKey != NULL)
			delete[] DRMKey;
	}
}
