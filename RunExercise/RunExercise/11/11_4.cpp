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
		std::cout << "������ �������� ��� ����������? (b/a): "; std::cin >> user_choice;
		if (user_choice == 'b')       // ��������� ����� ������-�������� �����
			ptr_pub[n] = new Book; //     � ������
		else                      // ��������� ����� ������-������������
			ptr_pub[n] = new Type; //     � ������
		std::cout << "���� ������ ������� " << n + 1 << ":";
		ptr_pub[n++]->getData();   // ������� ������ ������� � ������������
		std::cout << "\n������ ��������� �������? (y/n): "; std::cin >> user_choice; std::cout << std::endl;
	} while (user_choice == 'y'); // ���� �����������, ���� ����� ���

	// ������� �� ����� ������ ��������� ���� �������
	for (int j = 0; j < n; j++)
	{
		std::cout << "������ ������� " << j + 1 << ":";
		ptr_pub[j]->putData();
		// ���� ������� ������� �������� �������, ������� ��������������� �������
		if (ptr_pub[j]->isOversize()) std::cout << " (������� �������� �������!)\n";
	}

	return 0;
}