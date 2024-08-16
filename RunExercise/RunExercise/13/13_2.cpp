#include "13_2.h"


Building::Building()
{
	// строка для номеров этажей
	char strFloorNum[BUFFER_LENGTH];
	init_graphics();
	clear_screen();
	m_elevator = new Elevator(this);

	// для каждого этажа
	for(int i = 0; i < COUNT_FLOORS; i++)
	{
		 // вывести номер этажа на экран
		set_cursor_pos(3, COUNT_FLOORS - i);
		_itoa_s(i + 1, strFloorNum, 10);
		std::cout << std::setw(3) << strFloorNum;
		m_floorRequests[dUP][i] = false;
		m_floorRequests[dDOWN][i] = false;
	}
}

Building::~Building()
{
	delete m_elevator;
}

void Building::elevator_start()
{
	display_floorRequest();
	m_elevator->chooseAction();
	m_elevator->move();
}

void Building::display_floorRequest() const
{
	for(int i = 0; i < COUNT_FLOORS; i++)
	{
		set_cursor_pos(SPACE, COUNT_FLOORS - i);
		// Стрелка вверх
		if(m_floorRequests[dUP][i] == true)
			{std::cout << "'\x25B2'";}
	}
}


