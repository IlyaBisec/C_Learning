// Используется специальный «адаптер функции», 
// называющийся bind1dt или bind2nd, для связывания аргумента с
// функциональным объектом.Пусть, например, мы ищем строку SearchName
// в строковом контейнере names. В этом случае необходимо писать такое выражение :
// ptr = find_if(names.begin(), names.end(), bind2nd(equal_to<string>(), SearchName));

#include "header.h"

int main15_9()
{
	std::vector<std::string> vector;

	vector.push_back("milk");
	vector.push_back("wolf");
	vector.push_back("book");
	vector.push_back("water");
	vector.push_back("car");

	std::cout << "Count strings: " << vector.size() << "\n";
	// Output strings
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << "  " << i << ". " << vector[i] << "\n";
	}
	std::string search_string;

	std::cout << "\nEnter string of search: ";
	std::getline(std::cin, search_string);

	std::vector<std::string>::iterator iterator;
	// Find string in the container
	iterator = std::find_if(vector.begin(), vector.end(),
		std::bind2nd(std::equal_to<std::string>(), search_string));

	if (iterator == vector.end())
	{
		std::cout << "\nThere is no such string in the vector\n";
	}
	else
	{
		std::cout << "String founded" << " her position: " << iterator - vector.begin() << ".\n";
	}

	return 0;
}