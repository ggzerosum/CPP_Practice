#include "headers.h"

namespace My_NameSpace
{
	//������
	ACCOUNT::ACCOUNT(void)
		:id(0), name(NULL), cash(0)
	{
		//empty
	}

	//������
	ACCOUNT::ACCOUNT(int id, const char* name, int cash)
		:id(id), cash(cash)
	{
		//�ؽ�Ʈ ũ�⸸ŭ �����Ҵ� �� �ؽ�Ʈ ����
		size_t len = strlen(name) + 1;
		this->name = new char[len];
		strcpy_s(this->name, len, name);
	}

	//���� ������
	ACCOUNT::ACCOUNT(const ACCOUNT &original)
		:id(original.id), cash(original.cash)
	{
		char* origin = original.name;
		size_t size = strlen(origin) + 1;
		this->name = new char[size];
		strcpy_s(this->name, size, origin);
	}

	//�Ҹ���
	ACCOUNT::~ACCOUNT(void)
	{
		if (name != NULL)
		{
			delete[] name;
		}
	}

	int ACCOUNT::GetID(void)
	{
		return id;
	}

	char* ACCOUNT::GetName(void)
	{
		return name;
	}

	int ACCOUNT::GetCash(void)
	{
		return cash;
	}

	void ACCOUNT::AddCash(int money)
	{
		this->cash += money;
	}

	bool ACCOUNT::MinusCash(int money)
	{
		if (this->cash < money)
			return false;

		this->cash -= money;
		return true;
	}
}