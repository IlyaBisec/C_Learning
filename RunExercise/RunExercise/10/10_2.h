// 'String' class, which accepts a string from the user
// and translates to upper or lower case

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "..\stdafx.h"
#include <cctype>

using namespace std;

namespace TenTwo
{
	class String
	{
	public:

		String(const char *s)
		{
			int length = strlen(s); // Calculate length of string
			m_ptrString = new char[length + 1];
			strcpy(m_ptrString, s);
		}

		~String()
		{
			cout << "Delete string \n";
			delete[] m_ptrString;
		}

		void display() const { cout << m_ptrString << "\n"; }
		void upit(); // Upper register
		void lowpit(); // Lower register

	private:
		char *m_ptrString;

	};
}