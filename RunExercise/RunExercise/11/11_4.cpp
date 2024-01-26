#include "11_4.h"

bool chapter_11::Type::isOversize() const
{
	return (m_recordTime > 90) ? true : false;
}

bool chapter_11::Book::isOversize() const
{
	return (m_countPage > 900) ? true : false;
}



//

using namespace chapter_11;

int main11_4()
{
	Publication *ptr_pub[100];
	int n = 0;
	char user_choice;

	do {
		std::cout << "Вводим бумажную или аудиокнигу? (b/a): "; std::cin >> user_choice;
		if (user_choice == 'b')       // поместить новый объект-бумажную книгу
			ptr_pub[n] = new Book; //     в массив
		else                      // поместить новый объект-аудиокассету
			ptr_pub[n] = new Type; //     в массив
		std::cout << "Ввод данных издания " << n + 1 << ":";
		ptr_pub[n++]->getData();   // получим данные издания у пользователя
		std::cout << "\nВвести следующее издание? (y/n): "; std::cin >> user_choice; std::cout << std::endl;
	} while (user_choice == 'y'); // цикл выполняется, пока ответ «да»

	// выведем на экран данные введенных выше изданий
	for (int j = 0; j < n; j++)
	{
		std::cout << "Данные издания " << j + 1 << ":";
		ptr_pub[j]->putData();
		// если издание слишком большого размера, выведем соответствующую пометку
		if (ptr_pub[j]->isOversize()) std::cout << " (слишком большого размера!)\n";
	}

	return 0;
}