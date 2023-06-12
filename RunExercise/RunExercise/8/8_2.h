#pragma once
#include "..\stdafx.h"

class String
{
private:

	enum{ SIZE = 80 };
	char mString[SIZE];

public:

	String() { strcpy_s(mString, ""); }
	String(char stringValue[])
	{
		strcpy_s(mString, stringValue);

	}

	void display() const
	{
		std::cout << mString;
	}

	String operator += (String string)const;
};