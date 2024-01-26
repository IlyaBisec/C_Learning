#pragma once

#include "../stdafx.h"

namespace chapter_11 {

	class OwnArray
	{
	public:
		OwnArray():m_pointer(0), m_size(0){}
		OwnArray(int temp)
		{
			m_size = temp;
			m_pointer = new int[temp];
		}
		OwnArray(OwnArray &own_array)
		{
			m_size = own_array.m_size;
			m_pointer = new int[m_size];

			for (int i = 0; i < m_size; i++)
			{
				*(m_pointer + 1) = *(own_array.m_pointer + i);
			}
		}

		~OwnArray() { delete[] m_pointer; }

		int &operator[] (int j){ return *(m_pointer + j);}

		OwnArray &operator= (OwnArray &own_array)
		{
			if (this == &own_array) return *this;
			delete[] m_pointer;

			m_size = own_array.m_size;
			m_pointer = new int[m_size];
			
			for (int i = 0; i < m_size; i++)
				*(m_pointer + i) = *(own_array.m_pointer + i);
			return *this;
		}

		void display() const              
		{
			for (int i = 0; i < m_size; i++)
				std::cout << *(m_pointer + i) <<" ";
		}

	private:
		int		*m_pointer;	// Pointer on the content array
		int		m_size;		// Count of elements in array
	};
}


int main11_3()
{
	const int SIZE = 10;
	chapter_11::OwnArray ownArray(SIZE);

	for (int j = 0; j < SIZE; j++)
		ownArray[j] = j * j;

	std::cout << "array 1 = "; ownArray.display(); std::wcout << std::endl;

	// Copy Constructor test
	chapter_11::OwnArray array2(ownArray);
	std::cout << "array 2 = "; ownArray.display(); std::wcout << std::endl;

	// arr==arr test
	chapter_11::OwnArray array_3(10), array_4(5), array_5(15);
	array_3 = ownArray; // при равном количестве элементов
	array_4 = ownArray; // количество элементов в присваиваемом массиве больше
	array_5 = ownArray; // количество элементов в присваиваемом массиве меньше
	// выведем на экран содержимое массивов arr3, arr4, arr5
	std::cout << "array_3 = "; array_3.display(); std::cout << std::endl;
	std::cout << "array_4 = "; array_4.display(); std::cout << std::endl;
	std::cout << "array_5 = "; array_5.display(); std::cout << std::endl;

	// тестируем присваивание самому себе
	ownArray = ownArray;
	// выведем на экран содержимое массива arr1
	std::cout << "ownArray = "; ownArray.display(); std::cout << std::endl;

	// тестируем множественное присваивание
	chapter_11::OwnArray array_6, array_7;
	array_7 = array_6 = ownArray;
	// выведем на экран содержимое массивов arr6, arr7
	std::cout << "array_6 = "; array_6.display(); std::cout << std::endl;
	std::cout << "array_7 = "; array_7.display(); std::cout << std::endl;

	return 0;

}