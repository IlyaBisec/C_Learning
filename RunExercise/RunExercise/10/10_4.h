// Linked List

#pragma once
#include "..\stdafx.h"
using namespace std;

namespace TenFour
{
	struct Link // Element of linklist
	{
		int data;   // Data
		Link* next; // Pointer on the next element of linklist
	};


	class LinkLists
	{
	public:
		LinkLists() { m_first = NULL; }
		~LinkLists();

		void addItem(int data);
		void display() const;

	private:
		Link* m_first;
	};
}