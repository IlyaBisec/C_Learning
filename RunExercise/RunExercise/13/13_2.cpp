#include "13_2.h"

// Building

Building::Building()
{
	// A string for floor numbers
	char strFloorNum[BUFFER_LENGTH];
	init_graphics();
	clear_screen();
	m_currNumCabines = 0;

	// Create elevators
	for(int i = 0; i < NUM_CABINES; i++)
	{
		m_cabineList[i] = new Elevator(this, NUM_CABINES);
		m_currNumCabines++;
	}
	// For each floor
	for(int j = 0; j < NUM_FLOORS; j++)
	{
		// Display the floor number on the screen
		set_cursor_pos(3, NUM_FLOORS - j);
		_itoa_s(j + 1, strFloorNum, 10);
		std::cout << std::setw(3) << strFloorNum;
		m_floorRequests[dUP][j] = false;
		m_floorRequests[dDOWN][j] = false;
	}
}

Building::~Building()
{
	// Delete elevators
	for (int i = 0; i < NUM_CABINES; i++)
		delete m_cabineList[i];
}

void Building::elevator_start()
{
	int i;
	display_floorRequest();
	for (i = 0; i < NUM_CABINES; i++)
		m_cabineList[i]->elevatorTick();
	for (i = 0; i < NUM_CABINES; i++)
		m_cabineList[i]->elevatorTick2();
}

int Building::get_elevFloor(const int numberCabine) const
{
	return m_cabineList[numberCabine]->get_floor();
}

EDirection Building::get_elevDir(const int numberCabine) const
{
	return m_cabineList[numberCabine]->get_direction();
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
	char inputSymbol = 'x';	// Addition symbol for the input
	char tempString[BUFFER_LENGTH]; // Addition string for the input

	int floor;	// Floor from request
	char choose_direction;	// 'u'(up) or d(down)

	set_cursor_pos(1, 22);

	std::cout << "Enter [Enter] for start of elevator: ";
	if (!_kbhit()) // Wait '\r'
		return;

	std::cin.ignore(10, '\n');

	inputSymbol = _getch();
	if (inputSymbol == '\x1B') // If Esc
		exit(0);

	set_cursor_pos(1, 22); clear_line();
	set_cursor_pos(1, 22);

	std::cout << "What floor are you on? ";
	std::cin.get(tempString, BUFFER_LENGTH);
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
	for (int i = 0; i < NUM_FLOORS; i++)
	{
		set_cursor_pos(SPACE, NUM_FLOORS - i);
		// Up arrow
		if (m_floorRequests[dUP][i] == true)
		{
			std::cout << "'\x1E'";
		} else
		{
			std::cout << ' ';
		}
		set_cursor_pos(SPACE + 3, NUM_FLOORS - i);
		// Down arrow
		if (m_floorRequests[dDOWN][i] == true)
		{
			std::cout << "\x1F";
		} else
		{
			std::cout << ' ';
		}
	}
}


// Elevator

Elevator::Elevator(Building *build, int numberCabine):
	m_ptrBuilding(build), m_cabineNumber(numberCabine)
{
	m_currentFloor = 0;	// Current floor 0(for user - 1)
	m_oldFloor = 0;		// pre floor also 0
	// While the elevator car is in place
	m_currentDir = dSTOP;

	// The passenger has not yet pressed the button with the destination floor
	for (int i = 0; i < NUM_FLOORS; i++)
		destination[i] = false;

	m_timerLoad = 0;
	m_timerUnload = 0;
}

void Elevator::elevatorTick()
{
	display();
	floor_display();
	if (m_timerLoad)
		--m_timerLoad;
	if (m_timerUnload)
		--m_timerUnload;
	decideAction();
}

void Elevator::elevatorTick2()
{
	move();
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
	set_cursor_pos(SPACE + (m_cabineNumber + 1) * SPACE, NUM_FLOORS - m_oldFloor);
	std::cout << "  ";

	// Display of loading into the elevator
	set_cursor_pos(SPACE - 1 + (m_cabineNumber + 1) * SPACE, NUM_FLOORS - m_currentFloor);
	switch (m_timerLoad)
	{
		// The elevator door is closed, there is no passenger
		case 0:
			std::cout << " \xDB\xDB\xDB ";
			break;
			// The elevator door closes, the passenger is inside the cabin 
			// and he is not visible
		case 1:
			std::cout << " \xDB\xDB\xDB ";
			break;
			// A passenger inside the cabin with the door open
		case 2:
			std::cout << " \xDB\x01\xDB ";
			get_destination();
			break;
			// The elevator door opens, the passenger wants to enter (on the left)
		case 3:
			std::cout << " \x01\xDB\xDB ";
			break;
		default:
			break;
	}

	// Displaying the unloading from the elevator
	set_cursor_pos(SPACE + (m_cabineNumber + 1) * SPACE, NUM_FLOORS - m_currentFloor);
	switch (m_timerUnload)
	{
		// The elevator door is closed, there is no passenger
		case 0:
			std::cout << " \xDB\xDB\xDB ";
			break;
			// The elevator door closes, the passenger is inside the cabin and he is not visible
		case 1:
			std::cout << " \xDB\xDB\xDB ";
			break;
			// The door is open, the passenger got out of the elevator (to the right)
		case 2:
			std::cout << " \xDB\x01\xDB ";
			break;
			// The elevator door opens, the passenger inside the cabin is visible
		case 3:
			std::cout << " \xDB\x01\xDB ";
			break;
		default:
			break;
	}

	m_oldFloor = m_currentFloor;
}

void Elevator::floor_display() const
{
	for (int i = 0; i < NUM_FLOORS; i++)
	{
		set_cursor_pos(SPACE - 2 + (m_cabineNumber + 1) * SPACE, NUM_FLOORS - i);
		if (destination[i] == true)
		{
			std::cout << "\xFE"; // Small square
		} else
		{
			std::cout << " ";
		}
	}
}

void Elevator::decideAction()
{
	int i;

	bool destins_above, destins_below;  // The final destination
	bool requests_above, requests_below; // Requests from floors

	// The floor number of the nearest request from the floors above and below
	int nearest_high_request = 0;
	int nearest_low_request = 0;

	// The flags indicate if there are other elevators moving in 
	// the same direction between us and the nearest request from the floor
	bool cabine_between_up, cabine_between_down;

	// Flags indicate whether there are elevators in the opposite
	// direction on the other side of the nearest one
	bool cabine_opposite_up, cabine_opposite_down;

	int ofFloor; // Floor
	EDirection direction; // Direction

	// Checking for boundaries (upper and lower floors are the last ones)
	if ((m_currentFloor == NUM_FLOORS - 1 && m_currentDir == dUP)
		|| (m_currentFloor == 0 && m_currentDir == dDOWN)){
		m_currentDir = dSTOP;
	}

	// If you arrive, drop off the passenger
	if (destination[m_currentFloor] == true)
	{
		// Remove this destination from the list
		destination[m_currentFloor] = false;

		// Start disembarking the passenger
		if (!m_timerUnload)
			m_timerUnload = LOAD_TIME;
		return;
	}

	// If there is a request "up" from this floor and
	// If we are going up or standing, make a passenger boarding
	if ((m_ptrBuilding->get_floorRequest(dUP, m_currentFloor) && m_currentDir != dDOWN))
	{
		// If the elevator was standing
		m_currentDir = dUP;

		m_ptrBuilding->set_floorRequest(m_currentDir, m_currentFloor, false);
		if (!m_timerLoad)
			m_timerLoad = LOAD_TIME;
		return;
	}

	// If there is a request to "down" from this floor and
	// If we are going down or standing, make a passenger boarding
	if ((m_ptrBuilding->get_floorRequest(dDOWN, m_currentFloor) && m_currentDir != dUP))
	{
		// If the elevator was standing
		m_currentDir = dDOWN;

		m_ptrBuilding->set_floorRequest(m_currentDir, m_currentFloor, false);
		if (!m_timerLoad)
			m_timerLoad = LOAD_TIME;
		return;
	}

	// Check if there is a destination or requests from floors above and below
	// remember the nearest floor with a request from above and below
	destins_above = destins_below = false;
	requests_above = requests_below = false;


	// Checking the upper floors
	for (i = m_currentFloor + 1; i < NUM_FLOORS; i++)
	{
		// If it is the destination
		if (destination[i])
			destins_above = true;

		// If there is a request from this floor
		if (m_ptrBuilding->get_floorRequest(dUP, i) ||
			m_ptrBuilding->get_floorRequest(dDOWN, i))
		{
			requests_above = true;
			// If you have not previously remembered the floor
			if (!nearest_high_request)
				nearest_high_request = i; // Set nearest floor request
		}
	}

	// Checking the lower floors
	for (i = m_currentFloor - 1; i >= 0; i--)
	{
		// If it is the destination
		if (destination[i])
			destins_below = true;

		// If there is a request from this floor
		if (m_ptrBuilding->get_floorRequest(dUP, i) ||
			m_ptrBuilding->get_floorRequest(dDOWN, i))
		{
			requests_below = true;
			// If you have not previously remembered the floor
			if (!nearest_low_request)
				nearest_low_request = i; // Set nearest floor request
		}
	}

	// If there are no requests from floors or destination from above or below
	if (!destins_above && !requests_above &&
		!destins_below && !requests_below)
	{
		m_currentDir = dSTOP;
		return;
	}

	// If there is a destination, and the elevator is standing or moving towards it
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

	// Checking if there are other elevators, (a) in the same direction between us and the nearest one, or
	// (b) the opposite direction from the other side Floor Request(FR)
	cabine_between_up = cabine_between_up = false;
	cabine_opposite_up = cabine_opposite_down = false;

	// Checking every elevator
	for(i = 0; i < NUM_CABINES; i++)
	{
		// If it's not our elevator 
		if(i != NUM_CABINES)
		{
			// Get floor
			ofFloor = m_ptrBuilding->get_elevFloor(i);
			direction = m_ptrBuilding->get_elevDir(i);
		
			// If move up and floor request up
			if((direction == dUP || direction == dSTOP) && requests_above)
				// If He's between us at the same time
				if((ofFloor > m_currentFloor && ofFloor <= nearest_high_request)
					// or the same place, but his number is lower
					|| (ofFloor <= m_currentFloor && i < m_cabineNumber))
				{
					cabine_between_up = true;
				}
			// If move down and floor request down
			if((direction == dDOWN || direction == dSTOP) && requests_below)
				// If it is from below, but above the nearest one
				if((ofFloor < m_currentFloor && ofFloor >= nearest_low_request)
					// or the same place, but his number is 'too' lower
					|| (ofFloor <= m_currentFloor && i < m_cabineNumber))
				{
					cabine_between_down = true;
				}

			// If move up, ànd floor reqeust down
			if((direction == dUP || direction == dSTOP) && requests_below)
			// and lower him than floor request and nearest him, than we
				if(nearest_low_request >= ofFloor
					&& nearest_low_request - ofFloor
					< m_currentFloor - nearest_low_request)
				{
					cabine_opposite_up = true;
				}

			// If move down, and Floor request up
			if((direction == dDOWN || direction == dSTOP) && requests_above)
				// and his over floor request and nearest him, than we
				if(ofFloor >= nearest_high_request
					&& ofFloor - nearest_high_request
					< nearest_high_request - m_currentFloor)
				{
					cabine_opposite_down = true;
				}
		} // END if(No our elevator)

	} // END for(for every elevator)
		
	  
	// If we are going up or stopped, and the floor request is above us
	// and there are no elevators going up
	// or going down over the floor request and closer to it than we are, then
	// go up
	if((m_currentDir == dUP || m_currentDir == dSTOP)
	&& requests_above && !cabine_between_up && !cabine_opposite_down)
	{
		m_currentDir = dUP;
		return;
	}
	// If we are going down or stopped, and there is a floor request from below,
	// and there are no elevators going down between us and the floor request
	// or under the floor request going up and closer to us to the floor request
	if((m_currentDir == dDOWN || m_currentDir == dSTOP)
	&& requests_below && !cabine_between_down && !cabine_between_up)
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
	std::cout << "The elevator" << (m_currentFloor + 1) << "stopped on the floor " << (m_currentFloor + 1) << "\nDestination floor (0 for end of entry)";
	for(int i = 1; i < NUM_FLOORS; i++)
	{
		set_cursor_pos(1, 24);
		std::cout << "Destination floor " << i << ": ";
		std::cin.get(tempString, BUFFER_LENGTH);
		std::cin.ignore(10, '\n');
		// Floors are numbered from 0, not from 1
		dest_floor = atoi(tempString);
		set_cursor_pos(1, 24); clear_line();

		if(dest_floor == 0)
		{
			set_cursor_pos(1, 22); clear_line();
			set_cursor_pos(1, 23); clear_line();
			set_cursor_pos(1, 24); clear_line();
			return;
		}
		--dest_floor;
		if(dest_floor == m_currentFloor)
		{
			--i; continue;
		}
		// Selecting the destination floor selects the direction of move
		if (i == 1 && m_currentDir == dSTOP)
			m_currentDir = (dest_floor < m_currentFloor) ? dDOWN : dUP;
		destination[dest_floor] = true;
		floor_display();
	}
}

int Elevator::get_floor() const
{
	return m_currentFloor;
}

EDirection Elevator::get_direction() const
{
	return m_currentDir;
}
