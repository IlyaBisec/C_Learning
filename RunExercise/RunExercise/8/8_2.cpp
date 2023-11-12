#define _CRT_SECURE_NO_WARNINGS

#include "8_2.h"
 

int main8_2()
{
	std::cout << "\n";
	String a = "ABC";
	String b  = "DEF";

	String c;

	a.displayString();
	b.displayString();

	c = a += b;
	a.displayString();
	c.displayString();

	c += a;
	c.displayString();


	std::cout << "\n";
	std::cin.get();

	return 0;
}


String &String::operator+=(const String &right)
{
	size_t newSize = this->m_size + right.m_size;
	char *temp = new char[newSize + 1];

	strcpy(temp, this->m_string);
	strcat(temp, right.m_string);

	delete[] this->m_string;

	this->m_string = temp;
	this->m_size = newSize;


	return *this;
}

void String::displayString() const 
{
	std::cout << m_string<<"\n";
}


