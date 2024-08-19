#include "13_4.h"
#include <iostream>

// Shop
const Product g_productShop[MAX_PRODUCTS] =
{
	{"Bread", EProductType::ptBakery, 1.00},
	{"Baton", EProductType::ptBakery, 1.28},
	{"Sugar", EProductType::ptBulk,   2.30},
	{"Milk",  EProductType::ptMilk,   2.10},
	{"Water", EProductType::ptLiquid, 3.50},
	{"Tomato", EProductType::ptVegetables, 12.03},
	{"Chicken", EProductType::ptMeat, 29.72},
	{"Cucumber", EProductType::ptVegetables, 10.90}
};

// Buyer
const Buyer buyer("Alex", EProductType::ptMeat, 30);


int main13_4()
{
	std::cout << "Welcome, " << buyer.getName() << ".\n";
	std::cout << "The store has " << MAX_PRODUCTS << "products.\n";
	std::cout << "\n";

	// The customer examines the books on the shelves of the store
	bool isTakeProduct = false;
	for(int i = 0; i < MAX_PRODUCTS; i++)
	{
		std::cout << i + 1 << "-st product: |" << g_productShop[i].getTitle() << "|. ";
		if(buyer.checkType(g_productShop[i]))
		{
			std::cout << "Favourite product type...";
			if(buyer.checkPrice(g_productShop[i]))
			{
				std::cout << "I have enough money...I'm take this!\n";
				isTakeProduct = true;
				break;
			}
			else
			{
				std::cout << "I don't have enough money.\n";
			}
		}
		else
		{
			std::cout << "I don't like it";
		}
		std::cout << "\n";
	}
	std::cout << "\n";

	// The customer leaves the store
	if(isTakeProduct)
	{
		std::cout << buyer.getName() << ": Thanks!";
	}
	else
	{
		std::cout << buyer.getName() << ": I hope you have a new owner!";
	}
	std::cout << "\n";

	return 0;
}