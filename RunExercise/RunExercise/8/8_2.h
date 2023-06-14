// Overloaded operation '+=' for
// string concatenation

#pragma once
#include "..\stdafx.h"

class String
{
public:

	String() { strcpy_s(mString, ""); }

	// for !E0415
	String(const char line[]) { strcpy_s(mString, line); }

	String operator += (String string)const;

	void display();
private:

	enum { SIZE = 80 };
	char mString[SIZE];

};