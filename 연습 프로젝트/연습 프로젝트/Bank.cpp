#include "headers.h"

namespace My_NameSpace
{
	//생성자
	BANK::BANK(void)
		:m_iSize(0), m_List(NULL)
	{
		//empty
	}

	//복사 생성자
	BANK::BANK(const BANK &original)
		:m_iSize(original.m_iSize)
	{
		ACCOUNT** origin = original.m_List;
		m_List = new ACCOUNT*[m_iSize];

		for (int i = 0; i < m_iSize; ++i)
		{
			m_List[i] = new ACCOUNT(*(origin[i]));
		}
	}

	//소멸자
	BANK::~BANK(void)
	{
		for (int i = 0; i < m_iSize; ++i)
		{
			delete m_List[i];
		}

		delete[] m_List;
	}

	void BANK::CreateList(void)
	{
		using std::cout;
		using std::endl;
		using std::cin;

		int iInput_id;
		int iInput_cash;
		char sInput_name[48] = { 0 };
		ACCOUNT** pTemp;

		cout << endl << "1. 개설할 계좌번호(\'-\'없는 숫자)" << endl << ": ";
		fnc_flush();
		cin >> iInput_id;

		cout << endl << "2. 계좌의 이름" << endl << ": ";
		fnc_flush();
		cin >> sInput_name;

		cout << endl << "3. 계좌 시작 금액" << endl << ": ";
		fnc_flush();
		cin >> iInput_cash;

		if (m_List == NULL)
		{
			//0에 1 더한 크기로 동적 할당(객체 포인터 변수)
			++m_iSize;
			m_List = new ACCOUNT*[m_iSize];
			
			//고객 객체 생성 및 포인터 변수에 주소값 대입
			*m_List = new ACCOUNT(iInput_id, sInput_name, iInput_cash);
		}
		else
		{
			//기존에 1 더해진 크기로 동적 할당
			pTemp = new ACCOUNT*[m_iSize + 1];

			//신규 포인터 배열에 기존 배열의 값 복사
			for (int i = 0; i < m_iSize; i++)
			{
				pTemp[i] = m_List[i];
			}

			//신규 포인터 배열의 마지막 요소 관리
			pTemp[m_iSize] = new ACCOUNT(iInput_id, sInput_name, iInput_cash);

			//기존 동적 할당 해제
			delete[] m_List;

			//주소값 대입, 크기 증가
			m_List = pTemp;
			++m_iSize;
		}
	}

	void BANK::Deposit(void)
	{
		using std::cout;
		using std::cin;
		using std::endl;

		int iInput_id, iInput_cash;

		cout << "1. 입금할 계좌번호" << endl << ": ";
		cin >> iInput_id;

		cout << endl << "2. 입금할 금액" << endl << ": ";
		cin >> iInput_cash;

		for (int i = 0; i < m_iSize; i++)
		{
			if (m_List[i]->GetID() == iInput_id)
			{
				m_List[i]->AddCash(iInput_cash);
				cout << endl << "입금이 완료되었습니다.";
				cout << endl << "현재 잔액: " << m_List[i]->GetCash();
				cout << endl;
				return;
			}
		}

		cout << endl << "유효하지 않은 ID입니다." << endl;
	}

	void BANK::Withdraw(void)
	{
		using std::cout;
		using std::cin;
		using std::endl;

		int iInput_id, iInput_cash;

		cout << "1. 출금할 계좌번호" << endl << ": ";
		cin >> iInput_id;

		cout << endl << "2. 출금할 금액" << endl << ": ";
		cin >> iInput_cash;

		for (int i = 0; i < m_iSize; i++)
		{
			if (m_List[i]->GetID() == iInput_id)
			{
				
				if (m_List[i]->MinusCash(iInput_cash))
				{
					cout << endl << "현재 계좌 잔액: " << m_List[i]->GetCash() << "원" << endl;
					return;
				}

				cout << endl << "계좌의 잔액보다 큰 액수는 출금할 수 없습니다." << endl;
				cout << "현재 잔액: " << m_List[i]->GetCash() << endl;
				return;
			}
		}

		cout << endl << "유효하지 않은 ID입니다" << endl;
	}

	void BANK::ShowList(void)
	{
		using std::cout;
		using std::endl;

		for (int i = 0; i < m_iSize; i++)
		{
			cout << "<" << (i + 1) << "번째 고객>" << endl
				<< "이름: " << m_List[i]->GetName() << endl
				<< "계좌: " << m_List[i]->GetID() << endl
				<< "잔액: " << m_List[i]->GetCash() << endl << endl;
		}
	}

	void BANK::fnc_flush(void)
	{
		int chr;
		while (((chr = getchar()) != '\n') && (chr != EOF));
	}
}