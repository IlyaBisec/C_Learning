#include "13_3.h"


namespace ElevatorSystemMod{

	// Building

	Building::Building()
	{
		// A string for floor numbers
		char strFloorNum[BUFFER_LENGTH];
		init_graphics();
		clear_screen();
		m_currentCountCabines = 0;

		// Creating elevators
		for(int i = 0; i < COUNT_CABINES; i++)
		{
			m_elevatorList[i] = new Elevator(this, m_currentCountCabines);
			m_currentCountCabines++;
		}

		// For each floor
		for (int i = 0; i < COUNT_FLOORS; i++)
		{
			// Display the floor number on the screen
			set_cursor_pos(3, COUNT_FLOORS - i);
			_itoa_s(i + 1, strFloorNum, 10);
			std::cout << std::setw(3) << strFloorNum;
			m_floorRequests[dUP][i] = false;
			m_floorRequests[dDOWN][i] = false;
		}
	}

	Building::~Building()
	{
		for (int i = 0; i < COUNT_CABINES; i++)
			delete m_elevatorList[i];
	}

	void Building::elevator_start()
	{
		int i;
		display_floorRequest();
		for (i = 0; i < COUNT_CABINES; i++)
			m_elevatorList[i]->chooseAction();
		for (int i = 0; i < COUNT_CABINES; i++)
			m_elevatorList[i]->move();
	}

	int Building::get_elevFloor(const int floor_number) const
	{
		return m_elevatorList[floor_number]->get_floor();
	}

	EDirection Building::get_elevDir(const int floor_number) const
	{
		return  m_elevatorList[floor_number]->get_direction();
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
		if (!_kbhit()) // Wait '\r'
			return;

		tempSymbol = _getch();
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
		for (int i = 0; i < COUNT_FLOORS; i++)
		{
			set_cursor_pos(SPACE, COUNT_FLOORS - i);
			// Up arrow
			if (m_floorRequests[dUP][i] == true)
			{
				std::cout << L"'\x25B2'";
			} else
			{
				std::cout << ' ';
			}
			set_cursor_pos(SPACE + 3, COUNT_FLOORS - i);
			// Down arrow
			if (m_floorRequests[dDOWN][i] == true)
			{
				std::cout << L"\x25BC";
			} else
			{
				std::cout << L' ';
			}
		}
	}


	// Elevator

	Elevator::Elevator(Building *build, int cabine_number): m_ptrBuilding(build), m_elevNumber(cabine_number)
	{
		m_currentFloor = 0;	// Current floor 0(for user - 1)
		m_oldFloor = 0;		// pre floor also 0
		// While the elevator car is in place
		m_currentDir = dSTOP;

		// The passenger has not yet pressed the button with the destination floor
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
		set_cursor_pos(SPACE + (m_elevNumber + 1) * SPACE, COUNT_FLOORS - m_oldFloor);
		std::cout << "  ";

		// Display of loading into the elevator
		set_cursor_pos(SPACE - 1 + (m_elevNumber + 1) *  SPACE, COUNT_FLOORS - m_currentFloor);
		switch (m_timerLoad)
		{
			// The elevator door is closed, there is no passenger
			case 0:
				std::cout << L" \x2588\x2588\x2588 ";
				break;
				// The elevator door closes, the passenger is inside the cabin 
				// and he is not visible
			case 1:
				std::cout << L" \x2588\x2588\x2588 ";
				break;
				// A passenger inside the cabin with the door open
			case 2:
				std::cout << L" \x2588\x263A\x2588 ";
				get_destination();
				break;
				// The elevator door opens, the passenger wants to enter (on the left
			case 3:
				std::cout << L" \x263A\x2588\x2588 ";
				break;
			default:
				break;
		}

		// Displaying the unloading from the elevator
		set_cursor_pos(SPACE + (m_elevNumber + 1) *  SPACE, COUNT_FLOORS - m_currentFloor);
		switch (m_timerUnload)
		{
			// The elevator door is closed, there is no passenger
			case 0:
				std::cout << L" \x2588\x2588\x2588 ";
				break;
				// The elevator door closes, the passenger is inside the cabin and he is not visible
			case 1:
				std::cout << L" \x2588\x2588\x2588 ";
				break;
				// The door is open, the passenger got out of the elevator (to the right)
			case 2:
				std::cout << L" \x2588\x2588\x263A ";
				break;
				// The elevator door opens, the passenger inside the cabin is visible
			case 3:
				std::cout << L" \x2588\x263A\x2588 ";
				break;
			default:
				break;
		}

		m_oldFloor = m_currentFloor;
	}

	void Elevator::floor_display() const
	{
		for (int i = 0; i < COUNT_FLOORS; i++)
		{
			set_cursor_pos(SPACE - 2 + (m_elevNumber + 1) * SPACE, COUNT_FLOORS - i);
			if (destination[i] == true)
			{
				std::cout << L"\x25A0";
			} else
			{
				std::cout << L" ";
			}
		}
	}

	void Elevator::decideAction()
	{
		int i;

		bool destins_above, destins_below;    // The final destination
		bool requests_above, requests_below;  // Requests from floors
		int count_req_above, count_req_below; // The number of requests from floors below and above

		// The floor number of the nearest request from the floors above and below
		int nearest_high_request = 0;
		int nearest_low_request = 0;

		// Is there another elevator moving in the same direction
		bool elev_betweenUp, elev_betweenDown;
		// Is there another elevator moving in the opposite direction
		bool elev_oppositeUp, elev_oppositeDown;
		// Number of elevator cabins above and below
		bool currentCountElevUp, currentCountElevDown;

		int floor;
		EDirection direction;

		// Checking for boundaries (upper and lower floors are the last ones)
		if ((m_currentFloor == COUNT_FLOORS - 1 && m_currentDir == dUP)
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

		// Check if there is a destination or requests from floors above and below
		// remember the nearest floor with a request from above and below
		destins_above = destins_below = false;
		requests_above = requests_below = false;
		count_req_above = count_req_below = 0;

		// Checking the upper floors
		for (i = m_currentFloor + 1; i < COUNT_FLOORS; i++)
		{
			// If it is the destination
			if (destination[i])
				destins_above = true;

			// If there is a request from this floor
			if (m_ptrBuilding->get_floorRequest(dUP, i) ||
				m_ptrBuilding->get_floorRequest(dDOWN, i))
			{
				requests_above = true;
				count_req_above++;
				// If you have not previously remembered the floor
				if (!nearest_high_request)
					nearest_high_request = i;
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
				count_req_below++;
				// If you have not previously remembered the floor
				if (!nearest_low_request)
					nearest_low_request = i;
			}
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

		// If there are no requests from floors or destination from above or below
		if (!destins_above && !requests_above &&
			!destins_below && !requests_below)
		{
			m_currentDir = dSTOP;
			return;
		}

		// If we are going up or stopped, and there is a request from the floor above us
		if ((m_currentDir == dUP || m_currentDir == dSTOP) && requests_above)
		{
			m_currentDir = dUP;
			return;
		}

		// If we are going down or stopped, and there is a request from the floor below us
		if ((m_currentDir == dUP || m_currentDir == dSTOP) && requests_below)
		{
			m_currentDir = dDOWN;
			return;
		}

		// Check if there are other elevators that:
		// moving in the same direction, between us and the nearest request from the floor;
		// or they are moving in the opposite direction, on the other side of the request from the floor
		elev_betweenUp = elev_betweenDown = false;
		elev_oppositeUp = elev_oppositeDown = false;
		currentCountElevUp = currentCountElevDown = 0;
		 // Check every elevator
		for (i = 0; i < COUNT_CABINES; i++)              
		{
			// If it's not the right elevator
			if (i != m_elevNumber)                        
			{
				// Get his floor and direction
				floor = m_ptrBuilding->get_elevFloor(i);
				direction = m_ptrBuilding->get_elevDir(i); 

				// If this elevator is heading up and there are requests from the floors above
				if ((direction == dUP || direction == dSTOP) && requests_above)
				{
					// If it is between us and the request from the floor
					if ((floor > m_currentFloor && floor <= nearest_high_request)
						// Or it is on our floor, but its number is smaller than ours
						|| (floor == m_currentFloor && i < m_elevNumber))
						elev_betweenUp = true;

					if (floor > m_currentFloor
						|| (floor == m_currentFloor && i < m_elevNumber))
						currentCountElevUp++;
				}

				// If this elevator is heading down and there are requests from the floors below
				if ((direction == dDOWN || direction == dSTOP) && requests_below)
				{
					// If he is between the request from the floor
					if ((floor < m_currentFloor && floor >= nearest_low_request)
						// Or he's on this floor, but his room is smaller than the right one
						|| (floor == m_currentFloor && i < m_elevNumber))
						elev_betweenDown = true;
				
					if (floor < m_currentFloor
						|| (floor == m_currentFloor && i < m_elevNumber))
						currentCountElevDown++;
				}

				// If this elevator is heading up and down there are requests from the floors
				if ((direction == dUP || direction == dSTOP) && requests_below)
					// If it is lower than the request from the floor and closer to it than the current one
					if (nearest_low_request >= floor
						&& nearest_low_request - floor < m_currentFloor - nearest_low_request)
					{
						elev_oppositeUp = true;
						currentCountElevDown++;
					}

				// If this elevator is heading down and there are requests from the floors above
				if ((direction == dDOWN || direction == dSTOP) && requests_above)
					// If it is higher than the request from the floor and closer to it than the current floor
					if (floor >= nearest_high_request
						&& floor - nearest_high_request < nearest_high_request - m_currentFloor)
					{
						elev_oppositeDown = true;
						currentCountElevUp++;
					}
			}
		}

		// If moving 'up' or stopped, and there is a request from the floor above
		// and there are no elevators going 'up' between the floors and the request from this floor
		// and there are no elevators leading down above the request from the current floor and being closer to it than the current one
		if ((m_currentDir == dUP || m_currentDir == dSTOP)
			&& requests_above && !elev_betweenUp && !elev_betweenDown)
		{
			m_currentDir = dUP; // Moving up
			return;             // Complete the decide process
		}

		// If moving 'down' or stopped, and there is a request from the floor below
		// and there are no elevators going 'down' between the floors and the request from this floor
		// and there are no elevators going up the subquery from the floor and being closer to it than this floor
		if ((m_currentDir == dDOWN || m_currentDir == dSTOP)
			&& requests_below && !elev_betweenDown && !elev_oppositeDown)
		{
			m_currentDir = dDOWN; // Moving down
			return;               // Complete the decide process
		}

		// If the elevator is going up or standing, there are requests from above
		// and there are elevators going up between the floors and the request from the floor
		// or are there elevators leading down above the request from the floor and located closer to it, than this floor,
		// and the number of these elevators is less than the number of requests from the floors above
		if ((m_currentDir == dUP || m_currentDir == dSTOP)
			&& requests_above && (elev_betweenUp || elev_oppositeUp)
			&& currentCountElevUp < count_req_above)
		{
			m_currentDir = dUP; // Moving up
			return;             // Complete the decide process
		}

		// If the elevator is going down or standing, there are requests from below,
		// and there are elevators leading down from the floor between the floors and the request
		// or are there elevators going up under the request from the floor and located closer to it, than this floor,
		// and the number of these elevators is less than the number of requests from the floors below
		if ((m_currentDir == dDOWN || m_currentDir == dSTOP)
			&& requests_below && (elev_betweenDown || elev_oppositeUp)
			&& currentCountElevDown < count_req_below)
		{
			m_currentDir = dDOWN; // Moving down
			return;			      // Complete the decide process
		}

		m_currentDir = dSTOP;
	}

	void Elevator::get_destination()
	{
		char tempString[BUFFER_LENGTH];
		int dest_floor;

		set_cursor_pos(1, 22); clear_line();
		set_cursor_pos(1, 22);
		std::cout << "The elevator" << (m_elevNumber + 1) << " stopped on the floor " << (m_currentFloor + 1) << "...";

		for (int i = 1; i < COUNT_FLOORS; i++){

			set_cursor_pos(1, 24);
			std::cout << "Enter"<<i<<" destination floor: ";

			std::cin.get(tempString, BUFFER_LENGTH);
			std::cin.ignore(10, '\n');
			// Floors are numbered from 0, not from 1
			dest_floor = atoi(tempString);
			set_cursor_pos(1, 24); clear_line();

			// Clear lines lower, if enter 0 for the exit
			if (dest_floor == 0)
			{
				set_cursor_pos(1, 22); clear_line();
				set_cursor_pos(1, 23); clear_line();
				set_cursor_pos(1, 24); clear_line();
				return;
			}
			--dest_floor;

			// If you have selected the current floor,
			if (dest_floor == m_currentFloor)
			{
				--i;
				continue;
			}

			// If the elevator was standing, selecting the destination floor selects the direction of move
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
}