// Класс person для хранения указателей на объекты 
// этого класса. 
// С помощью comparePersons - автоматически сортировать поименно людей
// Определить полдюжины элементов и внести их в мультимножество
// Вывести содержимое

#include "header.h"

namespace STL_15_4 {
	// Person - класс как запись о человеке в тел. книге
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
			std::cout << std::setiosflags(std::ios::left) << std::setw(STR_SIZE) <<
				m_lastName << std::setw(STR_SIZE) << m_firstName << "Phone: " << m_phoneNumber << "\n";
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

	// ComparePerson - класс сравнения объектов класса Person 
	// по указателям
	class ComparePersons
	{
	public:
		bool operator() (const Person *ptr_person1, const Person *ptr_person2) const
			{return *ptr_person1 < *ptr_person2; }
	};

	// displayPerson - функция для вывода на экран класса person
	// по указателю
	void displayPerson(const Person *ptr_person)
	{
		ptr_person->display();
	}
}


using namespace STL_15_4;

int main()
{
	// Multiset
	std::multiset<Person *, ComparePersons> multiPersons;

	// Выделение памяти на полдюжины персон и помещение их в 
	// мультимножество
	multiPersons.insert(new Person("Jackson", "Michael", 88005535));
	multiPersons.insert(new Person("Tirel", "Travis", 12345678));
	multiPersons.insert(new Person("Lannistar", "Tywin", 41414141));
	multiPersons.insert(new Person("King", "Stiven", 78234519));
	multiPersons.insert(new Person("Pika", "Chu", 77117711));
	multiPersons.insert(new Person("Jackson", "Michael", 88005535));

	// Output
	std::for_each(multiPersons.begin(), multiPersons.end(), displayPerson);

	// Осовбождеие памяти
	std::multiset<Person *, ComparePersons>::iterator iterator;
	for (iterator = multiPersons.begin(); iterator != multiPersons.end(); iterator++)
	{
		delete *iterator;
		multiPersons.erase(iterator);
	}
	return 0;


}