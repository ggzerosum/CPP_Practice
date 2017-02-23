#pragma once

namespace My_NameSpace
{
	class eBook : public Book
	{
	private:
		char* DRMKey;
	public:
		eBook(void);
		eBook(const char* title, const char* isbn, int price, const char* key);
		eBook(const eBook &copy);

		void SetKey(const char* str);
		const char* GetKey(void) const;
		void ShowEBookInfo(void) const;

		~eBook(void);
	};
}