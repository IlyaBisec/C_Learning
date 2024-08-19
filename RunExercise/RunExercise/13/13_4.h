#pragma once
// A class library simulating a grocery store

#ifdef _SHOP_PROJECT_LIB_
	#define CLASS_DECLSPEC _declspec(dllexport)
#else
	#define CLASS_DECLSPEC _declspec(dllimport)
#endif // _SHOP_PROJECT_LIB_

#include <string>

const unsigned int MAX_PRODUCTS = 8;

enum class EProductType
{
	ptBakery,
	ptBulk,
	ptLiquid,
	ptMeat,
	ptMilk,
	ptVegetables
};


// A class describing a food item in a store
class CLASS_DECLSPEC Product
{
public:
	Product(std::string title, EProductType product_type, float price):
		m_title(title), productType(product_type), m_price(price) { }

	std::string getTitle() const;
	EProductType getType() const;
	float getPrice() const;

private:
	std::string m_title;
	EProductType productType;
	float m_price;
};


// Buyer's class
class CLASS_DECLSPEC Buyer
{
public:
	Buyer(std::string name, EProductType favourite_product, float money):
		m_name(name), favouriteProduct(favourite_product), sumMoney(money) { }

	// Получить имя покупателя
	std::string getName() const; 
	// Проверить тип продукта
	bool checkType(const Product &product) const;
	// Проверить цену продукта
	bool checkPrice(const Product &product) const;

private:
	std::string m_name;
	EProductType favouriteProduct;
	float sumMoney;
	
};