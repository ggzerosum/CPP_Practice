#include "Inlcudes.h"

int main(void)
{
	namespace ns = My_NameSpace;

	ns::Book my_book("�ϴ��� ����", "PROVI-100", 16500);
	my_book.ShowBookInfo();

	ns::eBook my_ebook("����1", "PROVI-200", 12000, "DRM-001");
	my_ebook.ShowEBookInfo();

	my_ebook.SetIsbn("PROVI-770");
	my_ebook.ShowEBookInfo();
}