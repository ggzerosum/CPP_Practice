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
		:price(copy.price)
	{
		if (copy.title == NULL)
			title = NULL;
		else
			SetStrToDestination(title, copy.title);
		
		if (copy.isbn == NULL)
			isbn = NULL;
		else
			SetStrToDestination(isbn, copy.isbn);
	}

	void Book::SetStrToDestination(char* &destination, const char* source)
	{
		size_t size = strlen(source) + 1;
		destination = new char[size];
		strcpy_s(destination, size, source);
	}

	void Book::SetTitle(const char* str)
	{
		SetStrToDestination(title, str);
	}

	void Book::SetIsbn(const char* str)
	{
		SetStrToDestination(isbn, str);
	}

	void Book::SetPrice(int amount)
	{
		price = amount;
	}

	const char* Book::GetTitle(void) const
	{
		return title;
	}

	const char* Book::GetIsbn(void) const
	{
		return isbn;
	
	}

	int Book::GetPrice(void) const
	{
		return price;
	}

	void Book::ShowBookInfo(void) const
	{
		cout << "[도서 정보]" << endl;
		cout << "제목: " << title << endl;
		cout << "번호: " << isbn << endl;
		cout << "가격: " << price << endl;
	}

	Book::~Book()
	{
		if (title != NULL)
			delete[] title;

		if (isbn != NULL)
			delete[] isbn;
	}
}


