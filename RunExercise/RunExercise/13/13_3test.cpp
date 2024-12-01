#include "13_4.h"
#include <iostream>
#include <cassert>

// Function to test the constructor and methods of the Product class
void test_product() {
    Product bread("Bread", EProductType::ptBakery, 1.00);

    assert(bread.getTitle() == "Bread" && "Error: incorrect product name");
    assert(bread.getType() == EProductType::ptBakery && "Error: incorrect product type");
    assert(bread.getPrice() == 1.00 && "Error: incorrect product price");

    std::cout << "test_product passed\n";
}

// Function to test the constructor and methods of the Buyer class
void test_buyer() {
    Buyer buyer("Alex", EProductType::ptMeat, 30.00);

    assert(buyer.getName() == "Alex" && "Error: incorrect buyer name");

    Product meat("Chicken", EProductType::ptMeat, 29.72);
    Product bread("Bread", EProductType::ptBakery, 1.00);

    assert(buyer.checkType(meat) && "Error: buyer should like this product type");
    assert(!buyer.checkType(bread) && "Error: buyer should not like this product type");
    assert(buyer.checkPrice(meat) && "Error: buyer should have enough money");
    assert(!buyer.checkPrice(Product("Beef", EProductType::ptMeat, 50.00)) && "Error: buyer should not have enough money");

    std::cout << "test_buyer passed\n";
}

// Function to test the store logic
void test_store_logic() {
    const Product shopProducts[MAX_PRODUCTS] = {
        {"Bread", EProductType::ptBakery, 1.00},
        {"Baton", EProductType::ptBakery, 1.28},
        {"Sugar", EProductType::ptBulk, 2.30},
        {"Milk", EProductType::ptMilk, 2.10},
        {"Water", EProductType::ptLiquid, 3.50},
        {"Tomato", EProductType::ptVegetables, 12.03},
        {"Chicken", EProductType::ptMeat, 29.72},
        {"Cucumber", EProductType::ptVegetables, 10.90}
    };

    Buyer buyer("Alex", EProductType::ptMeat, 30);

    bool isTakeProduct = false;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (buyer.checkType(shopProducts[i])) {
            if (buyer.checkPrice(shopProducts[i])) {
                isTakeProduct = true;
                break;
            }
        }
    }

    assert(isTakeProduct && "Error: buyer should purchase a product");
    std::cout << "test_store_logic passed\n";
}

// Main function to run all tests
int main13_44() {
    test_product();
    test_buyer();
    test_store_logic();

    std::cout << "All tests passed successfully!\n";
    return 0;
}
