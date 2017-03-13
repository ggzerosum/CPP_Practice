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

	//�ε��� ������
	ACCOUNT* SmartArr::operator[](int idx)
	{
		if (idx < 0 || idx >= sizeOfList)
			exit(1);

		return list[idx];
	}

	//�߰� �Լ�
	bool SmartArr::add(ACCOUNT* ptr)
	{
		size_t temp_size;

		if (list == nullptr)
		{
			//0�� 1 ���� ũ��� ���� �Ҵ�(��ü ������ ����)
			//���Ǹ� ���ؼ� malloc ���.
			++sizeOfList;
			temp_size = sizeof(ACCOUNT*);
			list = (ACCOUNT**)malloc(temp_size);

			//������ ������ �� ��ü �ּҰ� ����
			list[0] = ptr;
			return true;
		}
		
		//������ 1 ������ ũ��� ���� �Ҵ�
		temp_size = sizeof(ACCOUNT*) * (sizeOfList + 1);
		list = (ACCOUNT**)realloc(list, temp_size);

		//Ȯ��� ������ �迭�� ������ ��� ����
		list[sizeOfList] = ptr;
		++sizeOfList;
		return true;
	}
}