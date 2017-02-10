#include "includes.h"

void main(void)
{
	namespace ns = My_NameSpace;
	namespace nsEnum = My_EnumSpace;
	
	ns::NAMECARD manClerk("������", "��ȭ �ɹ�Į", "010-7700-1014", nsEnum::CLERK);
	ns::NAMECARD manAssist("���ϳ�", "�ȴ�����", "010-5555-6766", nsEnum::ASSIST);

	manClerk.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
}