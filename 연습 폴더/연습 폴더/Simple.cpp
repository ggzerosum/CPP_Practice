#include "Inlcudes.h"

namespace My_NameSpace
{
	BASE::BASE()
		:m_private(7), m_protected(7), m_public(7)
	{
		cout << "BASE: constructor" << endl;
	}

	BASE::~BASE()
	{
		cout << "BASE: destructor" << endl;
	}

	void BASE::ShowInfo1(void)
	{
		cout << "BASE private: " << m_private << endl;
		cout << "BASE protected: " << m_protected << endl;
		cout << "BASE public: " << m_public << endl << endl;
	}

	DERIVED::DERIVED()
	{
		cout << "DERIVED: constructor" << endl;
	}
	
	DERIVED::~DERIVED()
	{
		cout << "DERIVED: destructor" << endl;
	}

	void DERIVED::ShowInfo(void)
	{
		ShowInfo1();
		//cout << "DERIVED private: " << m_private << endl;
		cout << "DERIVED protected: " << m_protected << endl;
		cout << "DERIVED public: " << m_public << endl;
	}
}