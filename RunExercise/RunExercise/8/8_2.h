// Overloaded operation '+=' for
// string concatenation

#pragma once
#include "..\stdafx.h"

class String
{
public:

	String(const char *string = "")
	{ 
		this->m_size = strlen(string);
		this->m_string = new char[this->m_size + 1];
		strcpy(this->m_string, string);
	}

	String(const String &source_string)
	{ 
		this->m_size = source_string.m_size;
		this->m_string = new char[this->m_size + 1];

		memcpy(this->m_string, source_string.m_string, this->m_size + 1);
	}

	~String() { delete[] this->m_string; }


	String &operator += (const String &string);

	void displayString() const;
private:

	size_t m_size = 80;
	char* m_string;

};