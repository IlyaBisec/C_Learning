#include "8_2.h"

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


int main8_2()
{
	// check a book for true example

	//String firstLine = "\nHey!\n";
	//String secondLine = "\nI'm here!\n";
	String firstLine, secondLine,thirdLine;

	firstLine.display();
	secondLine.display();
	thirdLine.display();

	thirdLine = firstLine += secondLine;

	std::cout << "\n";
	std::cin.get();

	return 0;
}