// Getting file size with help cmd, app_name.exe file_name.txt

#include "pre12.h"

int main12_3(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "The file must be specified as a parameter \n";
		return 1;
	}

	const char *fileName = argv[1];

	std::ifstream file(fileName);

	if (!file)
	{
		std::cerr << "Error opennig file: " << fileName << "\n";
		return 1;
	}

	file.seekg(0, std::ios::end);
	std::cout << fileName << " size: " << file.tellg() << " bytes\n";

	return 0;
}