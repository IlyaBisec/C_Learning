// Copy contetns from source to destination file

#include "pre12.h"


int main12_2(int argc, char *argv[])
{
	// Check numbers of parameter
	// 1 - file_name.exe
	// 2 - source file_name.txt
	// 3 - destination file_name.txt
	if (argc != 3)
	{
		std::cerr << "Commnad error! Usage: "<<argv[0]<<" <src_file> <destination_file> \n";
		return 1;
	}

	const char *src_fileName = argv[1], 
		       *dest_fileName = argv[2];


	std::ifstream sourceFile(src_fileName);
	//except("Error opennig src file: ", argv, 1, sourceFile);
	if (!sourceFile)
	{
		std::cerr << "Error opennig src file: "<<src_fileName <<"\n";
		return 1;
	}

	std::ofstream destinationFile(dest_fileName);
	if (!destinationFile)
	{
		std::cerr << "Error opennig dest file: " << dest_fileName << "\n";
		return 1;
	}

	char choice;
	while (sourceFile.get(choice))
		destinationFile.put(choice);

	std::cout << "Success! File copied from"<<src_fileName<<" to "<<dest_fileName<<"\n";

	return 0;
}


template <typename T> void except(const std::string &message, char *argv[], int index, const T argument)
{
	if(!argument)
	{
		std::cerr << message << argv[index] << "\n";
		return 1;
	}
}
