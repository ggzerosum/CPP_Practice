#include "headers.h"

using namespace std;
namespace err = My_EnumSpace;

namespace My_NameSpace
{
	HANDLER* HANDLER::ptr = NULL;

	HANDLER::HANDLER()
	{
	}

	HANDLER::~HANDLER()
	{
		HANDLER::ptr = NULL;
	}

	void HANDLER::AddAccountToList(BANK &ref)
	{
		int id;
		int cash;
		char name[48] = { 0 };

		cout << endl << "1. ������ ���¹�ȣ(\'-\'���� ����)" << endl << ": ";
		fnc_flush();
		cin >> id;

		cout << endl << "2. ������ �̸�" << endl << ": ";
		fnc_flush();
		cin >> name;

		cout << endl << "3. ���� ���� �ݾ�" << endl << ": ";
		fnc_flush();
		cin >> cash;

		ref.CreateList(id, name, cash);
	}

	void HANDLER::Deposit(BANK &ref)
	{
		int id, cash, error_code;

		cout << "1. �Ա��� ���¹�ȣ" << endl << ": ";
		fnc_flush();
		cin >> id;

		cout << endl << "2. �Ա��� �ݾ�" << endl << ": ";
		fnc_flush();
		cin >> cash;

		error_code = ref.Deposit(id, cash);

		switch (error_code)
		{
		case err::SUCCESS:
			cout << endl << "�Ա��� �Ϸ�Ǿ����ϴ�.";
			cout << endl << "���� �ܾ�: " << ref.GetCashOfAccount(id) << endl;
			break;

		default:
			cout << endl << "��ȿ���� ���� ID�Դϴ�." << endl;
			break;
		}
	}

	void HANDLER::Withdraw(BANK &ref)
	{
		int id, cash, error_code;

		cout << "1. ����� ���¹�ȣ" << endl << ": ";
		fnc_flush();
		cin >> id;

		cout << endl << "2. ����� �ݾ�" << endl << ": ";
		fnc_flush();
		cin >> cash;

		error_code = ref.Withdraw(id, cash);

		switch (error_code)
		{
		case err::SUCCESS:
			cout << endl << "���� ���� �ܾ�: " << ref.GetCashOfAccount(id) << "��" << endl;
			break;

		case err::ID:
			cout << endl << "��ȿ���� ���� ID�Դϴ�" << endl;
			break;

		case err::CASH:
			cout << endl << "������ �ܾ׺��� ū �׼��� ����� �� �����ϴ�." << endl;
			cout << "���� �ܾ�: " << ref.GetCashOfAccount(id) << endl;
			break;
		}
	}

	void HANDLER::ShowInfo(BANK &ref)
	{
		ref.ShowList();
	}

	HANDLER* HANDLER::itSelf(void)
	{
		if (HANDLER::ptr == NULL)
		{
			HANDLER::ptr = new HANDLER;
		}

		return HANDLER::ptr;
	}
}