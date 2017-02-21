#include "headers.h"

namespace err = My_EnumSpace;

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

	void BANK::CreateList(int id, const char* name, int cash)
	{
		ACCOUNT** pTemp;

		if (m_List == NULL)
		{
			//0에 1 더한 크기로 동적 할당(객체 포인터 변수)
			++m_iSize;
			m_List = new ACCOUNT*[m_iSize];
			
			//고객 객체 생성 및 포인터 변수에 주소값 대입
			*m_List = new ACCOUNT(id, name, cash);
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
			pTemp[m_iSize] = new ACCOUNT(id, name, cash);

			//기존 동적 할당 해제
			delete[] m_List;

			//주소값 대입, 크기 증가
			m_List = pTemp;
			++m_iSize;
		}
	}

	int BANK::Deposit(int id, int cash)
	{
		for (int i = 0; i < m_iSize; i++)
		{
			if (m_List[i]->GetID() == id)
			{
				m_List[i]->AddCash(cash);
				return err::SUCCESS;
			}
		}

		return err::ID;
	}

	int BANK::Withdraw(int id, int cash)
	{
		for (int i = 0; i < m_iSize; i++)
		{
			if (m_List[i]->GetID() == id)
			{
				if (m_List[i]->MinusCash(cash))
					return err::SUCCESS;
				else
					return err::CASH;
			}
		}

		return err::ID;
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

	int BANK::GetCashOfAccount(int id)
	{
		for (int i = 0; i < m_iSize; i++)
		{
			if (m_List[i]->GetID() == id)
				return m_List[i]->GetCash();
		}

		return 0;
	}
}