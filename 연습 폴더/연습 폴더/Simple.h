#pragma once

namespace My_NameSpace
{
	class BASE
	{
	private:
		int m_private;
	protected:
		int m_protected;
	public:
		int m_public;
	public:
		BASE();
		~BASE();
	public:
		void ShowInfo1(void);
	};

	class DERIVED : public BASE
	{
	public:
		DERIVED();
		~DERIVED();
	public:
		void ShowInfo(void);
	};
}