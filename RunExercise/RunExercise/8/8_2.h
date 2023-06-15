// Overloaded operation '+=' for
// string concatenation

#pragma once
#include "..\stdafx.h"

class String
{
public:

	String() { strcpy_s(mString, ""); }

	// For !E0415. If not declare this constructor,
	// in this case, it will result in a E0415 error and a memory leak
	String(const char line[]) { strcpy_s(mString, line); }

	String operator += (String string)const;

	void display();
private:

	enum { SIZE = 80 };
	char mString[SIZE];

};