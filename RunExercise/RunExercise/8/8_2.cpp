#include "8_2.h"

int main8_2()
{
	String firstLine = "\nHey!";
	String secondLine  = "I'm here!";

	String thirdLine;

	firstLine.displayString();
	secondLine.displayString();
	thirdLine.displayString();

	thirdLine = firstLine += secondLine;

	std::cout << "\n";
	std::cin.get();

	return 0;
}

String String::operator+=(const String &string)
{
	String tempString;

	if (strlen(mString) + strlen(string.mString) < SIZE)
	{
		// Copying content of the first line
		strcpy_s(tempString.mString, mString);
	
		// and adding content of the second line
		strcat_s(tempString.mString, mString);
	}
	else {
		std::cout << "Overflow \n";
		exit(1);
	}

	return *this;
}

void String::displayString() const 
{
	std::cout << mString;
}


