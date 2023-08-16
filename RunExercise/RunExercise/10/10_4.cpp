#include "10_4.h"

int main10_4()
{
	TenFour::LinkList linkList;

	linkList.addItem(1);
	linkList.addItem(2);
	linkList.addItem(3);
	linkList.addItem(4);
	linkList.addItem(5);

	linkList.display();

	return 0;
}

namespace TenFour
{

	LinkList::~LinkList()
	{
		Link *ptr_currentLink = m_First;
		while (ptr_currentLink)
		{
			m_First = ptr_currentLink->next;
			delete ptr_currentLink;
			cout << "Element deleted\n";
			ptr_currentLink = m_First;
		}
	}
	void LinkList::addItem(int data)
	{
		
		// We allocate memory for a new list item
	    // We save data to it a pointer to the next item in the list
		// will now point to an element that
		// before that was the first
		// the newly created element is now the first

		Link *ptr_newLink = new Link;
		ptr_newLink->data = data;
		ptr_newLink->next = m_First;

		m_First = ptr_newLink;
	}
	
	void LinkList::display() const
	{
		Link * ptr_currentLink = m_First;
		while (ptr_currentLink)
		{
			cout << ptr_currentLink->data << "\n";
			ptr_currentLink = ptr_currentLink->next;
		}
	}
}