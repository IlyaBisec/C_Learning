// Inheritance of the String class 
#pragma once

#include "..\stdafx.h"

class String
{
public:

	String() { p_line[0] = '\0'; }
	// convert our String to string
	String(const char line[]) { strcpy_s(p_line, line); }

	void display() const;

	operator char* ();

protected:
	char p_line[LENGTH];
};

class Pstring : public String
{
public:
	//line[]
	Pstring() : String(){};
	Pstring(const char str[]);
};

