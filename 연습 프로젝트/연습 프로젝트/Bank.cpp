#include "headers.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "Bank.h"

namespace My_NameSpace
{
	BANK* BANK::ptr = nullptr;

	//생성자
	BANK::BANK(void)
		:m_iSize(0), m_List()
	{
		//empty
	}

	//복사 생성자(Private으로 선언. 금지.)
	BANK::BANK(const BANK &original)
	{
		//empty
	}

	//대입 연산자 금지
	void BANK::operator=(const BANK &origin)
	{
		//empty
	}

	//소멸자
	BANK::~BANK(void)
	{
	}


	void BANK::ShowMenu(void)
	{
		cout	<< "\n====================\n"
				<< "1. 계좌 개설\n"
				<< "2. 입금\n"
				<< "3. 출금\n"
				<< "4. 전체 계좌 조회\n"
				<< "5. 종료\n"
				<< "====================\n";
	}

	void BANK::CreateList(void)
	{
		namespace ES = My_EnumSpace;

		int check;
		ACCOUNT* ptr;

		cout << endl << "0. 어떤 계좌를 개설하시겠습니까?";
		cout << endl << "(1번: 보통 계좌, 2번: 우대 계좌)" << endl << ": ";
		fnc_flush();
		cin >> check;

		//고객 객체 생성
		switch (check)
		{
		case ES::NORMAL:
			ptr = MakeNormalAccountObj();
			break;
			
		default:
			ptr = MakeHighCreditAccountObj();
			break;
		}

		//스마트 배열을 통해 알아서 동적 할당 및 확장.
		if (m_List.add(ptr))
			++m_iSize;
	}

	void BANK::Deposit(void)
	{
		int id, cash;

		cout << "1. 입금할 계좌번호" << endl << ": ";
		fnc_flush();
		cin >> id;

		cout << endl << "2. 입금할 금액" << endl << ": ";
		fnc_flush();
		cin >> cash;

		for (int i = 0; i < m_iSize; i++)
		{
			if (m_List[i]->GetID() == id)
			{
				m_List[i]->Deposit(cash);
				return;
			}
		}

		cout << endl << "유효하지 않은 ID입니다." << endl;
	}

	void BANK::Withdraw(void)
	{
		int id, cash;

		cout << "1. 출금할 계좌번호" << endl << ": ";
		fnc_flush();
		cin >> id;

		cout << endl << "2. 출금할 금액" << endl << ": ";
		fnc_flush();
		cin >> cash;

		for (int i = 0; i < m_iSize; i++)
		{
			if (m_List[i]->GetID() == id)
			{
				m_List[i]->Withdraw(cash);
				return;
			}
		}

		cout << endl << "유효하지 않은 ID입니다." << endl;
	}

	void BANK::ShowList(void)
	{
		for (int i = 0; i < m_iSize; i++)
		{
			cout << "<" << (i + 1) << "번째 고객>" << endl;
			m_List[i]->ShowInfo();
			cout << endl;
		}
	}

	ACCOUNT* BANK::MakeNormalAccountObj(void)
	{
		int id, cash, interest;
		char name[48] = { 0 };

		cout << endl << "1. 개설할 계좌번호(\'-\'없는 숫자)" << endl << ": ";
		fnc_flush();
		cin >> id;

		cout << endl << "2. 계좌의 이름" << endl << ": ";
		fnc_flush();
		cin >> name;

		cout << endl << "3. 계좌 시작 금액" << endl << ": ";
		fnc_flush();
		cin >> cash;

		cout << endl << "4. 기본 이자율" << endl << ": ";
		fnc_flush();
		cin >> interest;

		return new NormalAccount(id, name, cash, interest);
	}


	ACCOUNT* BANK::MakeHighCreditAccountObj(void)
	{
		int id, cash, interest, grade;
		char name[48] = { 0 };

		cout << endl << "1. 개설할 계좌번호(\'-\'없는 숫자)" << endl << ": ";
		fnc_flush();
		cin >> id;

		cout << endl << "2. 계좌의 이름" << endl << ": ";
		fnc_flush();
		cin >> name;

		cout << endl << "3. 계좌 시작 금액" << endl << ": ";
		fnc_flush();
		cin >> cash;

		cout << endl << "4. 기본 이자율" << endl << ": ";
		fnc_flush();
		cin >> interest;

		cout << endl << "5. 등급(1=>A, 2=>B, 3=>C)" << endl << ": ";
		fnc_flush();
		cin >> grade;

		return new HighCreditAccount(id, name, cash, interest, grade);
	}


	BANK* BANK::itSelf(void)
	{
		if (!BANK::ptr)
		{
			BANK::ptr = new BANK;
		}

		return BANK::ptr;
	}
}