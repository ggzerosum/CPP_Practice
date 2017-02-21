#include "Inlcudes.h"

namespace My_NameSpace
{
	Book::Book(void)
		:title(NULL), isbn(NULL), price(0)
	{}

	Book::Book(const char* title, const char* isbn, int price)
		:price(price)
	{
		SetStrToDestination(this->title, title);
		SetStrToDestination(this->isbn, isbn);
	}

	Book::Book(const Book &copy)
	{}

	void Book::SetStrToDestination(char* &destination, const char* source)
	{
		size_t size = strlen(source) + 1;
		destination = new char[size];
		strcpy_s(destination, size, source);
	}

	void Book::SetTitle(void)
	{}

	void Book::SetIsbn(void)
	{}

	void Book::SetPrice(void)
	{}

	char* Book::GetTitle(void) const
	{}

	char* Book::GetIsbn(void) const
	{}

	int Book::GetPrice(void) const
	{}

	void Book::ShowBookInfo(void) const
	{}

	Book::~Book()
	{
	}
}


