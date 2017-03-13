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
		
		//대입 연산자
		Book& operator=(const Book &copy);

		void SetTitle(const char* str);
		void SetIsbn(const char* str);
		void SetPrice(int amount);
		const char* GetTitle(void) const;
		const char* GetIsbn(void) const;
		int GetPrice(void) const;
		void ShowBookInfo(void) const;

		~Book(void);
	};
}



