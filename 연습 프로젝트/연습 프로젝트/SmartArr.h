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

		//인덱스 연산자
		ACCOUNT* operator[](int idx);

		//추가 함수
		bool add(ACCOUNT* ptr);
	};
}