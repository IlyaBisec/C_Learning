#include "8_2.h"

int main8_2()
{
	// check a book for true example

	String firstLine = "\nHey!";
	String secondLine  = "I'm here!";

	String thirdLine;

	firstLine.display();
	secondLine.display();
	thirdLine.display();

	thirdLine = firstLine += secondLine;

	std::cout << "\n";
	std::cin.get();

	return 0;
}

String String::operator += (String string) const
{
	String tempString;

	if (strlen(mString) + strlen(string.mString) < SIZE)
	{
		// copy content of the first line
		strcpy_s(tempString.mString, mString);
	
		// and add content of the second line
		strcat_s(tempString.mString, mString);
	}
	else {
		std::cout << "Overflow \n";
		exit(1);
	}

	return tempString;
}

void String::display()
{
	std::cout << mString;
}


