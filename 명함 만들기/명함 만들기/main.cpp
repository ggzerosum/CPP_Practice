#include "includes.h"

void main(void)
{
	namespace ns = My_NameSpace;
	namespace nsEnum = My_EnumSpace;

	ns::NAMECARD manClerk("리성룡", "한화 케미칼", "010-7700-1014", nsEnum::CLERK);
	ns::NAMECARD manSenior("홍백희", "오렌지 엔지니어", "010-3330-4044", nsEnum::SENIOR);
	ns::NAMECARD manAssist("송하나", "오버워치", "010-5555-6766", nsEnum::ASSIST);

	manClerk.ShowNameCardInfo();
	manSenior.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
}