// ����� person ��� �������� ���������� �� ������� 
// ����� ������. 
// � ������� comparePersons - ������������� ����������� �������� �����
// ���������� ��������� ��������� � ������ �� � ���������������
// ������� ����������

#include "header.h"

namespace STL_15_4 {
	// Person - ����� ��� ������ � �������� � ���. �����
	class Person
	{
	public:
		Person() : m_lastName("Empty"), m_firstName("Empty"), m_phoneNumber(0L)
		{ }
		Person(const std::string &lastName, const std::string &fisrtName, long phone):
			m_lastName(lastName), m_firstName(m_firstName), m_phoneNumber(phone)
		{ }

		friend bool operator< (const Person &, const Person &);

		void display() const
		{
			std::cout << std::setiosflags(std::ios::left) << std::setw(INDENTATION) <<
				m_lastName << std::setw(INDENTATION) << m_firstName << "Phone: " << m_phoneNumber << "\n";
		}

	private:
		std::string m_lastName;
		std::string m_firstName;

		long m_phoneNumber;
	};

	bool operator<(const Person &person1, const Person &person2)
	{
		if (person1.m_lastName == person2.m_lastName)
		{
			return (person1.m_firstName < person2.m_firstName) ? true : false;
		}
		return (person1.m_lastName < person2.m_lastName) ? true : false;
	}

	// ComparePerson - ����� ��������� �������� ������ Person 
	// �� ����������
	class ComparePersons
	{
	public:
		bool operator() (const Person *ptr_person1, const Person *ptr_person2) const
			{return *ptr_person1 < *ptr_person2; }
	};

	// displayPerson - ������� ��� ������ �� ����� ������ person
	// �� ���������
	void displayPerson(const Person *ptr_person)
	{
		ptr_person->display();
	}
}


using namespace STL_15_4;

int main15_4()
{
	// Multiset
	std::multiset<Person *, ComparePersons> multiPersons;

	// ��������� ������ �� ��������� ������ � ��������� �� � 
	// ���������������
	multiPersons.insert(new Person("Jackson", "Michael", 880055));
	multiPersons.insert(new Person("Tirel", "Travis", 123456));
	multiPersons.insert(new Person("Lannistar", "Tywin", 414141));
	multiPersons.insert(new Person("King", "Stiven", 782345));
	multiPersons.insert(new Person("Pika", "Chu", 771177));
	multiPersons.insert(new Person("Jackson", "Michael", 880055));

	// Output
	std::for_each(multiPersons.begin(), multiPersons.end(), displayPerson);

	// ����������� ������
	std::multiset<Person *, ComparePersons>::iterator iterator;
	for (iterator = multiPersons.begin(); iterator != multiPersons.end(); iterator++)
	{
		delete *iterator;
		multiPersons.erase(iterator);
	}
	return 0;


}