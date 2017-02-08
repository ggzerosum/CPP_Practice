#include "headers.h"

namespace My_NameSpace
{
	bank::bank(void)
		:m_iSize(0), m_List(NULL)
	{
		//empty
	}

	bank::~bank(void)
	{
		for (int i = 0; i < m_iSize; i++)
		{
			delete m_List[i];
		}
	}

	void bank::CreateList(void)
	{
		using std::cout;
		using std::endl;
		using std::cin;

		int iInput_id;
		int iInput_cash;
		char sInput_name[48] = { 0 };
		size_t len;
		ACCOUNT* pTemp;

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
			//0에 1 더한 크기로 동적 할당
			m_iSize++;
			m_List = new ACCOUNT[m_iSize];

			//이름 텍스트 크기만큼 동적할당
			len = strlen(sInput_name) + 1;
			m_List->name = new char[len];

			//이름용 동적할당 공간에 텍스트 복사
			strcpy_s(m_List->name, len, sInput_name);

			//계좌, 잔액 값 대입
			m_List->id = iInput_id;
			m_List->cash = iInput_cash;
		}
		else
		{
			//기존에 1 더해진 크기로 동적 할당
			pTemp = new ACCOUNT[m_iSize + 1];

			//신규 구조체에 기존 구조체의 값 복사
			for (int i = 0; i < m_iSize; i++)
			{
				pTemp[i] = m_List[i];
			}

			//신규 구조체 배열의 마지막 요소 관리
			//---이름
			len = strlen(sInput_name) + 1;
			pTemp[m_iSize].name = new char[len];
			strcpy_s(pTemp[m_iSize].name, len, sInput_name);

			//---계좌 및 잔액
			pTemp[m_iSize].id = iInput_id;
			pTemp[m_iSize].cash = iInput_cash;

			//기존 동적 할당 해제
			delete[] m_List;

			//주소값 대입, 크기 증가
			m_List = pTemp;
			++m_iSize;
		}
	}

	void bank::Deposit(void)
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
			if (m_List[i].id == iInput_id)
			{
				m_List[i].cash += iInput_cash;
				cout << endl << "입금이 완료되었습니다.";
				cout << endl << "현재 잔액: " << m_List[i].cash;
				cout << endl;
				return;
			}
		}

		cout << endl << "유효하지 않은 ID입니다." << endl;
	}

	void bank::Withdraw(void)
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
			if (m_List[i].id == iInput_id)
			{
				if (m_List[i].cash < iInput_cash)
				{
					cout << endl << "계좌의 잔액보다 큰 액수는 출금할 수 없습니다." << endl;
					cout << "현재 잔액: " << m_List[i].cash << endl;
					return;
				}

				m_List[i].cash -= iInput_cash;
				cout << endl << "현재 계좌 잔액: " << m_List[i].cash << "원" << endl;
				return;
			}
		}

		cout << endl << "유효하지 않은 ID입니다" << endl;
	}

	void bank::ShowList(void)
	{
		using std::cout;
		using std::endl;

		for (int i = 0; i < m_iSize; i++)
		{
			cout << (i + 1) << "번째 고객" << endl
				<< "이름: " << m_List[i].name << endl
				<< "계좌: " << m_List[i].id << endl
				<< "잔액: " << m_List[i].cash << endl << endl;
		}
	}

	void bank::fnc_flush(void)
	{
		int chr;
		while (((chr = getchar()) != '\n') && (chr != EOF));
	}
}