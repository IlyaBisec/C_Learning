#include "13_2.h"
#include <stdlib.h>

// Building

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

int Building::get_elevFloor() const
{
	return m_elevator->get_floor();
}

EDirection Building::get_elevDir() const
{
	return m_elevator->get_direction();
}

bool Building::get_floorRequest(const int direction, const int floor) const
{
	return m_floorRequests[direction][floor];
}

void Building::set_floorRequest(const int direction, const int floor, const bool updown)
{
	m_floorRequests[direction][floor] = updown;
}

void Building::record_floorRequest()
{
	char tempSymbol = 'x';	// Addition symbol for the input
	char tempString[BUFFER_LENGTH]; // Addition string for the input

	int floor;	// Floor from request
	char choose_direction;	// 'u'(up) or d(down)

	set_cursor_pos(1, 22);

	std::cout << "Enter [Enter] for start of elevator or [ESC} for the exit from programm: ";
	if (!kbhit()) // Wait '\r'
		return;

	tempSymbol = _getwch();
	if (tempSymbol == '\x1B') // If Esc
		exit(0);

	set_cursor_pos(1, 22); clear_line();
	set_cursor_pos(1, 22);

	std::cout << "Enter a floor number, when u are here: ";
	std::cin.get(choose_direction);
	std::cin.ignore(10, '\n');
	floor = atoi(tempString); // Convert char to int

	std::cout << "Enter direction for move 'u' - up or 'd' - down: ";
	std::cin.get(choose_direction);
	std::cin.ignore(10, '\n');

	// Requests for direction
	if (choose_direction == 'u' || choose_direction == 'U')
		m_floorRequests[dUP][floor - 1] = true;
	if (choose_direction == 'd' || choose_direction == 'D')
		m_floorRequests[dDOWN][floor - 1] = true;

	// Clear text
	set_cursor_pos(1, 22); clear_line();
	set_cursor_pos(1, 23); clear_line();
	set_cursor_pos(1, 24); clear_line();
}

void Building::display_floorRequest() const
{
	for(int i = 0; i < COUNT_FLOORS; i++)
	{
		set_cursor_pos(SPACE, COUNT_FLOORS - i);
		// Стрелка вверх
		if (m_floorRequests[dUP][i] == true)
			{std::cout << "'\x25B2'";} 
		else
			{std::cout << ' ';}
		set_cursor_pos(SPACE + 3, COUNT_FLOORS - i);
		// Стрелка вниз
		if (m_floorRequests[dDOWN][i] == true)
			{std::cout << "\x25BC";}
		else
			{std::cout << ' ';}
	}
}


// Elevator

