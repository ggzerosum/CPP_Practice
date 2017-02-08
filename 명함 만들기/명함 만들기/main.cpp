#include "includes.h"

void main(void)
{
	namespace ns = My_NameSpace;
	namespace nsEnum = My_EnumSpace;

	ns::NAMECARD manClerk("������", "��ȭ �ɹ�Į", "010-7700-1014", nsEnum::CLERK);
	ns::NAMECARD manSenior("ȫ����", "������ �����Ͼ�", "010-3330-4044", nsEnum::SENIOR);
	ns::NAMECARD manAssist("���ϳ�", "������ġ", "010-5555-6766", nsEnum::ASSIST);

	manClerk.ShowNameCardInfo();
	manSenior.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
}