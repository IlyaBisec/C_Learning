#define _CRT_SECURE_NO_WARNINGS
#include "9_2.h"


int main9_2()
{
	Pstring s1;

	char longLine[] = "Good programmers write code that humans can understand";	
	s1 = longLine;

	s1.display();

	Pstring s2 = " Heheh!";

	std::cout << static_cast<char *>(s2);
	std::cout << std::endl;

	// For testing the protective properties of the Pstring class in
	// case of object definition
	// with strings longer than (LENGTH - 1)

	// Very long string
	Pstring s3 =
		"Learning to program has no more to do with designing interactive "
		"software than learning to touch type has to do with writing poetry";
	
	s3.display();
	std::cout << std::endl;

	return 0;
}

void String::display() const
{
	std::cout << p_line;
}

String::operator char* ()
{
	return p_line;
}

Pstring::Pstring(const char str[])
{
	int i;
	for (i = 0; i < LENGTH - 1; i++)
	{
		p_line[i] = str[i];
	}
	p_line[i] = '\0';
}
