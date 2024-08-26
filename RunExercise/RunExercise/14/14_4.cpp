#include "14_4.h"

using namespace Template_14_4;

int main14_4()
{
    // Int
    int a = 23, b = 32;
    std::cout << "int: " << a << " " << b << ", ";
    swap(a, b);
    std::cout << "Swap: " << a << " " << b << "\n";

    // Double
    double da = 23.20, db = -32.12;
    std::cout << "double: " << da << " " << db << ", ";
    swap(da, db);
    std::cout << "Swap: " << da << " " << db << "\n";

    // Char
    char ca = 'A', cb = 'd';
    std::cout << "char: " << ca << " " << cb << ", ";
    swap(ca, cb);
    std::cout << "Swap: " << ca << " " << cb << "\n";

    return 0;
}