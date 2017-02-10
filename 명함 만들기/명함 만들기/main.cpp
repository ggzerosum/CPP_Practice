#include "includes.h"

void main(void)
{
	namespace ns = My_NameSpace;
	namespace nsEnum = My_EnumSpace;
	
	ns::NAMECARD manClerk("리성룡", "한화 케미칼", "010-7700-1014", nsEnum::CLERK);
	ns::NAMECARD manAssist("송하나", "옴닉조선", "010-5555-6766", nsEnum::ASSIST);

	manClerk.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
}