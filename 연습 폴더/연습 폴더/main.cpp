#include "Inlcudes.h"

int main(void)
{
	namespace ns = My_NameSpace;

	ns::Book my_book("ÇÏ´ÃÀÇ º°ºû", "PROVI-100", 16500);
	my_book.ShowBookInfo();

	ns::eBook my_ebook("µ¿»ê1", "PROVI-200", 12000, "DRM-001");
	my_ebook.ShowEBookInfo();

	ns::Book my_book2 = my_ebook;
	my_book2.ShowBookInfo();
}