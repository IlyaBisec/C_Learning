#include "9_1.h"

int main()
{
	

	return 0;
}

void Publication::getData()
{
	std::cout << "Input tittle: ";
	std::cin.get(p_Tittle, LENGTH);

	std::cout << "\nInput price: ";
	std::cin>>p_Price;
}

void Publication::putData() const
{
	std::cout << "Tittle: " << p_Tittle << "\n";
	std::cout << "Price: " << p_Price << "\n";
}
