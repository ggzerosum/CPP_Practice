#ifndef CHECK_HEADER

#define CHECK_HEADER

namespace hana_bank
{
	typedef struct account_list
	{
		int id;
		char* name;
		int cash;
	}LIST;

	class bank
	{
	private:
		int m_iSize;
		LIST* m_List;
	public:
		void Init(void);
		void CreateList(void);
		void Deposit(void);
		void Withdraw(void);
		void ShowList(void);
		void DeleteList(void);
	};

	void fnc_flush(void);
}

#endif