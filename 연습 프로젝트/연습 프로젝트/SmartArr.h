#pragma once

#include "Common.h"
#include "Account.h"

namespace My_NameSpace
{
	class SmartArr : public COMMON
	{
	private:
		ACCOUNT** list;
		int sizeOfList;
	public:
		SmartArr();
		~SmartArr();

		//�ε��� ������
		ACCOUNT* operator[](int idx);

		//�߰� �Լ�
		bool add(ACCOUNT* ptr);
	};
}