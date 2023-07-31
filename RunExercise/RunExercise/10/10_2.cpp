#include "10_2.h"

int main10_2()
{
	//char str[] = "Hey, how are u?";

	TenTwo::String string1 = "Hey, how are u?";
	TenTwo::String string2 = "Who knows nothing doubts nothing.";

	cout << "string 1 \n";
	string1.upit();
	string1.display();

	string1.lowpit();
	string1.display();

	cout << "string 2 \n";
	string2.upit();
	string2.display();

	string2.lowpit();
	string2.display();

	return 0;
}

namespace TenTwo {

	void String::upit()
	{
		int length = strlen(m_ptrString); // Calculate length of string
		for (int i = 0; i < length; i++)
			*(m_ptrString + i) = towupper(*(m_ptrString + i));
	}
	void String::lowpit()
	{
		int length = strlen(m_ptrString); // Calculate length of string
		for (int i = 0; i < length; i++)
			*(m_ptrString + i) = tolower(*(m_ptrString + i));
	}

}