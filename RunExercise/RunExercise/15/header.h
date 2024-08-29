#pragma once
#include <iostream>
#include <string>

#include <iomanip>
#include <list>
#include <set>
#include <algorithm>
#include <vector>


constexpr int SIZE = 80;
constexpr int MAX_COUNT = 100;
constexpr int LIMIT = 3;

// Get input values from user:
// string - ���������, ��� ������ ������ ������������
// user_enter - ��� ������������ ������(���)
// data_array - ��������� ��� �������� ������� ������
// answer - ���������� y/n ������������
template<class U, class D>
void getUserData(const std::string &string, U &user_enter, D &data_array, char &answer)
{
	do
	{
		std::cout << "Enter "<<string<<": ";
		std::cin >> user_enter;
		data_array.push_back(user_enter);
		std::cout << "And more? (y/n): ";
		std::cin >> answer;

	} while (answer != 'n');
}