#include "..\stdafx.h"

const int STRING_MAX_WIDTH = 80;

int main7_1()
{
	void reversit(char []);

	char value[STRING_MAX_WIDTH];
	std::cout << "Input your stritng: \n";
	// with spaces
	std::cin.get(value, STRING_MAX_WIDTH);	// bad good code
	
	reversit(value);

	std::cout << "Reversit string: \n";
	std::cout << value<<"\n";	// edoc doog dab

	return 0;
}

void reversit(char stringValue[])
{
	int length = std::strlen(stringValue);

	// reverse all symbols in the first half of the line 
	for (int i = 0; i < length / 2; i++)
	{
		char temp = stringValue[i];
		// in the second half
		stringValue[i] = stringValue[length - i - 1]; 
		stringValue[length - i - 1] = temp;
	}
}
