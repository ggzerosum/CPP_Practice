#pragma once

namespace My_NameSpace
{
	class Book
	{
	private:
		char* title;
		char* isbn;
		int price;
	protected:
		void SetStrToDestination(char* &destination, const char* source);
	public:
		Book(void);
		Book(const char* title, const char* isbn, int price);
		Book(const Book &copy);

		void SetTitle(void);
		void SetIsbn(void);
		void SetPrice(void);
		char* GetTitle(void) const;
		char* GetIsbn(void) const;
		int GetPrice(void) const;
		void ShowBookInfo(void) const;

		~Book(void);
	};
}



