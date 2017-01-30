#include <iostream>
#include <cstdlib>
#include <cstring>
#include "headers.h"

void hana_bank::fnc_create(LIST** ppList, int* pSize)
{
	using std::cout;
	using std::endl;
	using std::cin;

	int iInput_id;
	int iInput_cash;
	char sInput_name[48] = {0};
	size_t temp_size;
	LIST* pTemp;

	cout << endl << "1. 개설할 계좌번호(\'-\'없는 숫자)" << endl << ": ";
	fnc_flush();
	cin >> iInput_id;

	cout << endl << "2. 계좌의 이름" << endl << ": ";
	fnc_flush();
	cin >> sInput_name;

	cout << endl << "3. 계좌 시작 금액" << endl << ": ";
	fnc_flush();
	cin >> iInput_cash;

	if (*ppList == NULL)
	{
		//0에 1 더한 크기로 동적 할당
		(*pSize)++;
		temp_size = sizeof(LIST)*(*pSize);
		*ppList = (LIST*)malloc(temp_size);

		//이름 텍스트 크기만큼 동적할당
		temp_size = sizeof(char)*(strlen(sInput_name) + 1);
		(*ppList)->name = (char*)malloc(temp_size);
		
		//이름용 동적할당 공간에 텍스트 복사
		strcpy_s((*ppList)->name, temp_size, sInput_name);
		
		//계좌, 잔액 값 대입
		(*ppList)->id = iInput_id;
		(*ppList)->cash = iInput_cash;
	}
	else
	{
		//기존에 1 더해진 크기로 동적 할당
		temp_size = sizeof(LIST)*(*pSize + 1);
		pTemp = (LIST*)malloc(temp_size);

		//신규 구조체에 기존 구조체의 값 복사
		for (int i = 0; i < (*pSize); i++)
		{
			pTemp[i] = (*ppList)[i];
		}

		//신규 구조체 배열의 마지막 요소 관리
		//---이름
		temp_size = sizeof(char)*(strlen(sInput_name) + 1);
		pTemp[*pSize].name = (char*)malloc(temp_size);
		strcpy_s(pTemp[*pSize].name, temp_size, sInput_name);

		//---계좌 및 잔액
		pTemp[*pSize].id = iInput_id;
		pTemp[*pSize].cash = iInput_cash;

		//기존 동적 할당 해제
		free(*ppList);
		
		//주소값 대입, 크기 증가
		*ppList = pTemp;
		++(*pSize);
	}
}

void hana_bank::fnc_deposit(LIST*)
{

}

void hana_bank::fnc_withdraw(LIST*)
{

}

void hana_bank::fnc_total(LIST* pList, int iSize)
{
	using std::cout;
	using std::endl;

	for (int i = 0; i < iSize; i++)
	{
		cout << (i + 1) << "번째 고객" << endl
			<< "이름: " << pList[i].name << endl
			<< "계좌: " << pList[i].id << endl
			<< "잔액: " << pList[i].cash << endl << endl;		
	}
}

void hana_bank::fnc_flush(void)
{
	int chr;
	while (((chr = getchar()) != '\n') && (chr != EOF));
}