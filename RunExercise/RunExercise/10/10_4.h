// List

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

	class LinkList
	{
	public:
		LinkList() { m_First = NULL; }
		~LinkList(){}

		void addItem(int data);
		void display();

	private:
		Link* m_First;
	};
}