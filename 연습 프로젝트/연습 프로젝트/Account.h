#pragma once

namespace My_NameSpace
{
	class ACCOUNT
	{
	private:
		int id;
		char* name;
		int cash;
	public:
		ACCOUNT(void);
		ACCOUNT(int id, char* name = NULL, int cash = 0);
		~ACCOUNT(void);

		int GetID(void);
		char* GetName(void);
		int GetCash(void);
		void AddCash(int money);
		bool MinusCash(int money);
	};
}