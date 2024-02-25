#pragma once

#include "../stdafx.h"

namespace chapter11_9{
	struct Link
	{
		int data;
		Link *next;
	};

	class LinkList
	{
	public:
		LinkList(){ m_first = NULL; }
		LinkList(LinkList &list)
		{
			m_first = NULL;

			Link *current = list.m_first;
			while (current)
			{
				addItem(current->data);
				current = current->next;
			}
		}
		~LinkList()
		{
			Link *current = m_first;
			while (current)
			{
				m_first = current->next;
				delete current;
				std::cout << "Element deleted \n";
				current = m_first;
			}
		}

		void addItem(int item)
		{
			Link *newLink = new Link;
			newLink->data = item;
			newLink->next = m_first;
			m_first = newLink;
		}
		void displayList()
		{
			Link *current = m_first;
			while (current)
			{
				std::cout << current->data << " ";
				current = current->next;
			}
			std::cout << "\n";
		}

		LinkList &opertator = (LinkList & list)
		{
			if (this == &list) return *this;

			Link *current = m_first;
			while (current)
			{
				m_first = current->next;
				delete current;
				current = m_first;
			}

			current = list.m_file;
			while (current){
				addItem(current->data);
				current = current->next;
			}

			return *this;
		}

	private:
		Link *m_first;
	};
}

using namespace chapter11_9;
int main11_9()
{
	LinkList *list1 = new LinkList;
	list1->addItem(59);
	list1->addItem(360);
	list1->addItem(9);
	list1->addItem(41);

	std::cout << "list1= "; list1->displayList();

	LinkList list2(*list1);
	LinkList list3;
	list3 = *list1;

	std::cout << "list2= "; list2.displayList();
	std::cout << "list3= "; list3.displayList();

	return 0;
}