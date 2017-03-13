#include "headers.h"
#include "SmartArr.h"

namespace My_NameSpace
{
	SmartArr::SmartArr()
		:list(nullptr), sizeOfList(0)
	{}


	SmartArr::~SmartArr()
	{
		for (int i = 0; i < sizeOfList; i++)
		{
			delete list[i];
		}

		free(list);
	}

	//인덱스 연산자
	ACCOUNT* SmartArr::operator[](int idx)
	{
		if (idx < 0 || idx >= sizeOfList)
			exit(1);

		return list[idx];
	}

	//추가 함수
	bool SmartArr::add(ACCOUNT* ptr)
	{
		size_t temp_size;

		if (list == nullptr)
		{
			//0에 1 더한 크기로 동적 할당(객체 포인터 변수)
			//편의를 위해서 malloc 사용.
			++sizeOfList;
			temp_size = sizeof(ACCOUNT*);
			list = (ACCOUNT**)malloc(temp_size);

			//포인터 변수에 고객 객체 주소값 대입
			list[0] = ptr;
			return true;
		}
		
		//기존에 1 더해진 크기로 동적 할당
		temp_size = sizeof(ACCOUNT*) * (sizeOfList + 1);
		list = (ACCOUNT**)realloc(list, temp_size);

		//확장된 포인터 배열의 마지막 요소 관리
		list[sizeOfList] = ptr;
		++sizeOfList;
		return true;
	}
}