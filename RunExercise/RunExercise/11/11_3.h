#pragma once

// An array of one size is assigned an array of another (larger or smaller) size

#include "../stdafx.h"

namespace chapter_11 {

	// A class that models a regular array of integers
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
		int		*m_pointer;	// Pointer to the contents of the array
		int		m_size;		// The number of elements in the array
	};
}


