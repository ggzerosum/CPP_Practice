#pragma once

#include "Common.h"
#include "Account.h"

namespace My_NameSpace
{
	template<typename T>
	class SmartArr : public COMMON
	{
	private:
		T** list;
		int sizeOfList;
	public:
		SmartArr();
		~SmartArr();

		//�ε��� ������
		T* operator[](int idx);

		//�߰� �Լ�
		bool add(T* ptr);
	};


	template<typename T>
	SmartArr<T>::SmartArr()
		:list(nullptr), sizeOfList(0)
	{}


	template<typename T>
	SmartArr<T>::~SmartArr()
	{
		for (int i = 0; i < sizeOfList; i++)
		{
			delete list[i];
		}

		free(list);
	}

	//�ε��� ������
	template<typename T>
	T* SmartArr<T>::operator[](int idx)
	{
		if (idx < 0 || idx >= sizeOfList)
			exit(1);

		return list[idx];
	}

	//�߰� �Լ�
	template<typename T>
	bool SmartArr<T>::add(T* ptr)
	{
		size_t temp_size;

		if (list == nullptr)
		{
			//0�� 1 ���� ũ��� ���� �Ҵ�(��ü ������ ����)
			//���Ǹ� ���ؼ� malloc ���.
			++sizeOfList;
			temp_size = sizeof(T*);
			list = (T**)malloc(temp_size);

			//������ ������ �� ��ü �ּҰ� ����
			list[0] = ptr;
			return true;
		}

		//������ 1 ������ ũ��� ���� �Ҵ�
		temp_size = sizeof(T*) * (sizeOfList + 1);
		list = (T**)realloc(list, temp_size);

		//Ȯ��� ������ �迭�� ������ ��� ����
		list[sizeOfList] = ptr;
		++sizeOfList;
		return true;
	}
}