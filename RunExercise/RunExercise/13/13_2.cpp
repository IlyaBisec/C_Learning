#include "13_2.h"
#include <stdlib.h>

// Building

Building::Building()
{
	// ������ ��� ������� ������
	char strFloorNum[BUFFER_LENGTH];
	init_graphics();
	clear_screen();
	m_elevator = new Elevator(this);

	// ��� ������� �����
	for(int i = 0; i < COUNT_FLOORS; i++)
	{
		 // ������� ����� ����� �� �����
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
		// ������� �����
		if (m_floorRequests[dUP][i] == true)
			{std::cout << "'\x25B2'";} 
		else
			{std::cout << ' ';}
		set_cursor_pos(SPACE + 3, COUNT_FLOORS - i);
		// ������� ����
		if (m_floorRequests[dDOWN][i] == true)
			{std::cout << "\x25BC";}
		else
			{std::cout << ' ';}
	}
}


// Elevator

Elevator::Elevator(Building *build)
{
	m_currentFloor = 0;	// Current floor 0(for user - 1)
	m_oldFloor = 0;		// pre floor also 0
	//  ���� ������ ����� ����� �� �����
	m_currentDir = dSTOP; 

	// �������� ��� �� ������� ������ � ������ ����������
	for (int i = 0; i < COUNT_FLOORS; i++)
		destination[i] = false;

	m_timerLoad = 0;
	m_timerUnload = 0;
}

void Elevator::chooseAction()
{
	display();
	floor_display();
	if (m_timerLoad)
		--m_timerLoad;
	if (m_timerUnload)
		--m_timerUnload;
	decideAction();
}

void Elevator::move()
{
	if (m_timerLoad || m_timerUnload)
		return;
	if (m_currentDir == dUP)
		m_currentFloor++;
	else if (m_currentDir == dDOWN)
		m_currentFloor--;
}

void Elevator::display()
{
	set_cursor_pos(SPACE + SPACE, COUNT_FLOORS - m_oldFloor);
	std::cout << "  ";

	// ����������� �������� � ����
	set_cursor_pos(SPACE - 1 + SPACE, COUNT_FLOORS - m_currentFloor);
	switch (m_timerLoad)
	{
		// ����� ����� �������, ��������� ���
		case 0:
			std::cout << " \x2588\x2588\x2588 ";
			break;
		// ����� ����� �����������,�������� ������ ������ � ��� �� �����
		case 1:
			std::cout << " \x2588\x2588\x2588 ";
			break;
		// �������� ������ ������ � �������� ������
		case 2:
			std::cout << " \x2588\x263A\x2588 ";
			get_destination();
			break;
		// ����� ����� �����������, �������� ����� ����� (�����)
		case 3:
			std::cout << " \x263A\x2588\x2588 ";
			break;
		default:
			break;
	}

	// ����������� �������� �� �����
	set_cursor_pos(SPACE + SPACE, COUNT_FLOORS - m_currentFloor);
	switch (m_timerUnload)
	{
		// ����� ����� �������, ��������� ���
		case 0:
			std::cout << " \x2588\x2588\x2588 ";
			break;
		// ����� ����� �����������,�������� ������ ������ � ��� �� �����
		case 1:
			std::cout << " \x2588\x2588\x2588 ";
			break;
		// ����� �������, �������� ����� �� �����(�������)
		case 2:
			std::cout << " \x2588\x2588\x263A ";
			break;
		// ����� ����� �����������, ����� �������� ������ ������
		case 3:
			std::cout << " \x2588\x263A\x2588 ";
			break;
		default:
			break;
	}

	m_oldFloor = m_currentFloor;
}

void Elevator::floor_display() const
{
	for(int i = 0; i < COUNT_FLOORS; i++)
	{
		set_cursor_pos(SPACE - 2 + SPACE, COUNT_FLOORS - i);
		if(destination[i] == true)
		{
			std::cout << "\x25A0";
		}
		else
		{
			std::cout << " ";
		}
	}
}

void Elevator::decideAction()
{
	int i;

	bool destins_above,  destins_below;  // �������� �����
	bool requests_above, requests_below; // ������� � ������

	// ����� ����� ���������� ������� � ������ ���� � ����
	int nearest_high_request = 0;
	int nearest_low_request = 0;

	// �������� �� �������(������� � ������ ���� - �������� ����������)
	if((m_currentFloor == COUNT_FLOORS - 1 && m_currentDir == dUP)
		|| (m_currentFloor == 0 && m_currentDir == dDOWN)){ 
		m_currentDir = dSTOP; 
	}

	// ���� ��������, �������� ���������
	if(destination[m_currentFloor] == true)
	{
		// ������� ���� ����� ���������� �� ������
		destination[m_currentFloor] == false;

		// ������ ������� ���������
		if (!m_timerUnload)
			m_timerUnload = LOAD_TIME;
		return;
	}

	// ��������, ���� �� �������� ����� ��� ������� � ������ ���� � ���� �� ���;
	// �������� ��������� ���� � �������� ������ � ����� �� ���
	destins_above = destins_below = false;
	requests_above = requests_below = false;

	// ��������� ������� �����
	for(i = m_currentFloor + 1; i < COUNT_FLOORS; i++)
	{
		// ���� �� �������� ������� ����������,
		if(destination[i])
			destins_above = true;

		// ���� ���� ������ � ����� �����,
		if(m_ptrBuilding->get_floorRequest(dUP, i)||
			m_ptrBuilding->get_floorRequest(dDOWN, i))
		{
			requests_above = true;
			// ���� ����� �� �������� ����
			if (!nearest_high_request)
				nearest_high_request = i;
		}
	}
	 // ��������� ������ �����
	for(i = m_currentFloor - 1; i >= 0; i--)
	{
		// ���� �� �������� ������� ����������,
		if (destination[i])
			destins_below = true;

		// ���� ���� ������ � ����� �����
		if(m_ptrBuilding->get_floorRequest(dUP, i)||
			m_ptrBuilding->get_floorRequest(dDOWN, i))
		{
			requests_below = true;
			// ���� ����� �� �������� ����
			if (!nearest_low_request)
				nearest_low_request = i;
		}
	}

	// ���� ������� ����� ����������, � ���� ����� ��� �������� � ����,
	if (destins_above && (m_currentDir == dSTOP || m_currentDir == dUP))
	{
		m_currentDir = dUP;
		return;
	}
	if (destins_above && (m_currentDir == dSTOP || m_currentDir == dDOWN))
	{
		m_currentDir = dDOWN;
		return;
	}

	// ���� ���� ������ ������� � ����� ����� �
	// ���� �� ���� ����� ��� �����, ���������� ������� ���������
	if((m_ptrBuilding->get_floorRequest(dUP, m_currentFloor) && m_currentDir != dDOWN))
	{
		// ���� ���� �����
		m_currentDir = dUP;

		m_ptrBuilding->set_floorRequest(m_currentDir, m_currentFloor, false);
		if (!m_timerLoad)
			m_timerLoad = LOAD_TIME;
		return;
	}

	// ���� ���� ������ ����� � ����� ����� �
	// ���� �� ���� ���� ��� �����, ���������� ������� ���������
	if((m_ptrBuilding->get_floorRequest(dDOWN, m_currentFloor) && m_currentDir != dUP))
	{
		// ���� ���� �����
		m_currentDir = dDOWN;

		m_ptrBuilding->set_floorRequest(m_currentDir, m_currentFloor, false);
		if (!m_timerLoad)
			m_timerLoad = LOAD_TIME;
		return;
	}

	// ���� ��� �������� � ������ ��� ������ ���������� ������ ��� �����,
	if(!destins_above && !requests_above &&
		!destins_below && !requests_below)
	{
		m_currentDir = dSTOP;
		return;
	}

	// ���� �� ���� ����� ��� ������������, � ���� ��� ���� ������ � �����
	if((m_currentDir == dUP || m_currentDir == dSTOP) && requests_above)
	{
		m_currentDir = dUP;
		return;
	}

	// ���� �� ���� ���� ��� ������������, � ���� ��� ���� ������ � �����
	if((m_currentDir == dUP || m_currentDir == dSTOP) && requests_below)
	{
		m_currentDir = dDOWN;
		return;
	}

	m_currentDir = dSTOP;
}

void Elevator::get_destination()
{
	char tempString[BUFFER_LENGTH];
	int dest_floor;

	set_cursor_pos(1, 22); clear_line();
	set_cursor_pos(1, 22);
	std::cout << "���� ����������� �� ����� " << (m_currentFloor + 1) << "...";
	set_cursor_pos(1, 23);
	std::cout << "������� ���� ����������: ";
	std::cin.get(tempString, BUFFER_LENGTH);
	std::cin.ignore(10, '\n');
	// ����� ���������� � 0, � �� � 1
	dest_floor = atoi(tempString);
	--dest_floor;

	// ����� ����� ���������� �������� ����������� ��������
	m_currentDir = (dest_floor < m_currentFloor) ? dDOWN : dUP;
	destination[dest_floor] = true;
	floor_display();

	set_cursor_pos(1, 22); clear_line();
	set_cursor_pos(1, 23); clear_line();
	set_cursor_pos(1, 24); clear_line();
}

int Elevator::get_floor() const
{
	return m_currentFloor;
}

EDirection Elevator::get_direction() const
{
	return m_currentDir;
}
