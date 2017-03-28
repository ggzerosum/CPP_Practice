#include "headers.h"
#include "String.h"

namespace My_NameSpace
{
	String::String(const char* source)
	{
		if (source == nullptr)
		{
			str = nullptr;
			len = 0;
			return;
		}

		StrToDes(str, source);
		len = strlen(source);
	}

	String::String(const String &ref)
	{
		if (ref.str == nullptr)
		{
			str = nullptr;
			len = 0;
			return;
		}

		StrToDes(str, ref.str);
		len = ref.len;
	}

	String::~String()
	{
		if (str != nullptr)
			delete[] str;
	}

	String String::operator+(const String &ref) const
	{
		if (ref.str == nullptr)
			return *this;

		if (str == nullptr)
			return ref;

		size_t temp_size = len + ref.len + 1;
		char *temp = new char[temp_size];
		strcpy_s(temp, temp_size, str);
		strcat_s(temp, temp_size, ref.str);

		String result(temp);
		delete[] temp;
		return result;
	}

	String &String::operator+=(const String &ref)
	{
		if (ref.str == nullptr)
			return *this;

		if (str == nullptr)
		{
			len = ref.len;
			StrToDes(str, ref.str);
			return *this;
		}
		
		size_t temp_size = len + ref.len + 1;
		char *temp = new char[temp_size];
		strcpy_s(temp, temp_size, str);
		strcat_s(temp, temp_size, ref.str);

		delete[] str;
		StrToDes(str, temp);
		len = temp_size - 1;

		delete[] temp;
		return *this;
	}

	String &String::operator=(const String &ref)
	{
		if (str != nullptr)
			delete[] str;
		
		len = ref.len;
		if (ref.str == nullptr)
			str = nullptr;
		else
			StrToDes(str, ref.str);

		return *this;
	}

	bool operator==(const String &left, const String &right)
	{
		if (left.str == nullptr || right.str == nullptr)
		{
			if (left.str == nullptr && right.str == nullptr)
				return true;
			
			return false;
		}

		if (!strcmp(left.str, right.str))
			return true;
		else
			return false;
	}

	bool operator!=(const String &left, const String &right)
	{
		return !(left == right);
	}

	ostream &operator<<(ostream &left, const String &right)
	{
		left << right.str;
		return left;
	}

	istream &operator>>(istream &left, String &right)
	{
		char buffer[102];
		left >> buffer;
		right = String(buffer);

		return left;
	}
}