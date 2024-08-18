#include "13_3.h"


namespace ElevatorSystemMod{

	Building::Building()
	{
		// строка для номеров этажей
		char strFloorNum[BUFFER_LENGTH];
		init_graphics();
		clear_screen();
		m_currentCountCabines = 0;

		//  создаём лифты
		for(int i = 0; i < COUNT_CABINES; i++)
		{
			m_elevatorList[i] = new Elevator(this, m_currentCountCabines);
			m_currentCountCabines++;
		}

		// для каждого этажа
		for (int i = 0; i < COUNT_FLOORS; i++)
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
		for (int i = 0; i < COUNT_FLOORS; i++)
		{
			set_cursor_pos(SPACE, COUNT_FLOORS - i);
			// Стрелка вверх
			if (m_floorRequests[dUP][i] == true)
			{
				std::cout << "'\x25B2'";
			} else
			{
				std::cout << ' ';
			}
			set_cursor_pos(SPACE + 3, COUNT_FLOORS - i);
			// Стрелка вниз
			if (m_floorRequests[dDOWN][i] == true)
			{
				std::cout << "\x25BC";
			} else
			{
				std::cout << ' ';
			}
		}
	}


	// Elevator

	Elevator::Elevator(Building *build, int cabine_number): m_ptrBuilding(build), m_elevNumber(cabine_number)
	{
		m_currentFloor = 0;	// Current floor 0(for user - 1)
		m_oldFloor = 0;		// pre floor also 0
		//  пока кабина лифта стоит на месте
		m_currentDir = dSTOP;

		// пассажир еще не нажимал кнопку с этажом назначения
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

		// отображение погрузки в лифт
		set_cursor_pos(SPACE - 1 + (m_elevNumber + 1) *  SPACE, COUNT_FLOORS - m_currentFloor);
		switch (m_timerLoad)
		{
			// дверь лифта закрыта, пассажира нет
			case 0:
				std::cout << " \x2588\x2588\x2588 ";
				break;
				// дверь лифта закрывается,пассажир внутри кабины и его не видно
			case 1:
				std::cout << " \x2588\x2588\x2588 ";
				break;
				// пассажир внутри кабины с открытой дверьб
			case 2:
				std::cout << " \x2588\x263A\x2588 ";
				get_destination();
				break;
				// дверь лифта открывается, пассажир хочет войти (слева)
			case 3:
				std::cout << " \x263A\x2588\x2588 ";
				break;
			default:
				break;
		}

		// отображение выгрузки из лифта
		set_cursor_pos(SPACE + (m_elevNumber + 1) *  SPACE, COUNT_FLOORS - m_currentFloor);
		switch (m_timerUnload)
		{
			// дверь лифта закрыта, пассажира нет
			case 0:
				std::cout << " \x2588\x2588\x2588 ";
				break;
				// дверь лифта закрывается,пассажир внутри кабины и его не видно
			case 1:
				std::cout << " \x2588\x2588\x2588 ";
				break;
				// дверь открыта, пассажир вышел из лифта(направо)
			case 2:
				std::cout << " \x2588\x2588\x263A ";
				break;
				// дверь лифта открывается, виден пассажир внутри кабины
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
		for (int i = 0; i < COUNT_FLOORS; i++)
		{
			set_cursor_pos(SPACE - 2 + (m_elevNumber + 1) * SPACE, COUNT_FLOORS - i);
			if (destination[i] == true)
			{
				std::cout << "\x25A0";
			} else
			{
				std::cout << " ";
			}
		}
	}

	void Elevator::decideAction()
	{
		int i;

		bool destins_above, destins_below;    // конечный пункт
		bool requests_above, requests_below;  // запросы с этажей
		int count_req_above, count_req_below; // количество запросов с этажей ниже и выше

		// номер этажа ближайшего запроса с этажей выше и ниже
		int nearest_high_request = 0;
		int nearest_low_request = 0;

		// есть ли другой лифт, движущийся в том же
		// направлении
		bool elev_betweenUp, elev_betweenDown;
		// есть ли другой лифт, движущийся в противоположном
		// направлении
		bool elev_oppositeUp, elev_oppositeDown;
		// количество кабин лифтов сверху и снизу
		bool currentCountElevUp, currentCountElevDown;

		int floor;
		EDirection direction;

		// проверка на гранины(верхний и нижний этаж - являются последними)
		if ((m_currentFloor == COUNT_FLOORS - 1 && m_currentDir == dUP)
			|| (m_currentFloor == 0 && m_currentDir == dDOWN)){
			m_currentDir = dSTOP;
		}

		// если приехали, высадить пассажира
		if (destination[m_currentFloor] == true)
		{
			// удалить этот пункт назначения из списка
			destination[m_currentFloor] == false;

			// начать высадку пассажира
			if (!m_timerUnload)
				m_timerUnload = LOAD_TIME;
			return;
		}

		// проверим, есть ли конечный пункт или запросы с этажей выше и ниже от нас;
		// запомним ближайший этаж с запросом сверху и снизу от нас
		destins_above = destins_below = false;
		requests_above = requests_below = false;
		count_req_above = count_req_below = 0;

		// проверяем верхние этажи
		for (i = m_currentFloor + 1; i < COUNT_FLOORS; i++)
		{
			// если он является пунктом назначения,
			if (destination[i])
				destins_above = true;

			// если есть запрос с этого этажа,
			if (m_ptrBuilding->get_floorRequest(dUP, i) ||
				m_ptrBuilding->get_floorRequest(dDOWN, i))
			{
				requests_above = true;
				count_req_above++;
				// если ранее не запомнен этаж
				if (!nearest_high_request)
					nearest_high_request = i;
			}
		}
		// проверяем нижние этажи
		for (i = m_currentFloor - 1; i >= 0; i--)
		{
			// если он является пунктом назначения,
			if (destination[i])
				destins_below = true;

			// если есть запрос с этого этажа
			if (m_ptrBuilding->get_floorRequest(dUP, i) ||
				m_ptrBuilding->get_floorRequest(dDOWN, i))
			{
				requests_below = true;
				count_req_below++;
				// если ранее не запомнен этаж
				if (!nearest_low_request)
					nearest_low_request = i;
			}
		}

		// если имеется пункт назначения, а лифт стоит или движется к нему,
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

		// если есть запрос «вверх» с этого этажа и
		// если мы едем вверх или стоим, произвести посадку пассажира
		if ((m_ptrBuilding->get_floorRequest(dUP, m_currentFloor) && m_currentDir != dDOWN))
		{
			// если лифт стоял
			m_currentDir = dUP;

			m_ptrBuilding->set_floorRequest(m_currentDir, m_currentFloor, false);
			if (!m_timerLoad)
				m_timerLoad = LOAD_TIME;
			return;
		}

		// если есть запрос «вниз» с этого этажа и
		// если мы едем вниз или стоим, произвести посадку пассажира
		if ((m_ptrBuilding->get_floorRequest(dDOWN, m_currentFloor) && m_currentDir != dUP))
		{
			// если лифт стоял
			m_currentDir = dDOWN;

			m_ptrBuilding->set_floorRequest(m_currentDir, m_currentFloor, false);
			if (!m_timerLoad)
				m_timerLoad = LOAD_TIME;
			return;
		}

		// если нет запросов с этажей или пункта назначения сверху или снизу,
		if (!destins_above && !requests_above &&
			!destins_below && !requests_below)
		{
			m_currentDir = dSTOP;
			return;
		}

		// если мы едем вверх или остановились, а выше нас есть запрос с этажа
		if ((m_currentDir == dUP || m_currentDir == dSTOP) && requests_above)
		{
			m_currentDir = dUP;
			return;
		}

		// если мы едем вниз или остановились, а ниже нас есть запрос с этажа
		if ((m_currentDir == dUP || m_currentDir == dSTOP) && requests_below)
		{
			m_currentDir = dDOWN;
			return;
		}

		// проверим, есть ли другие лифты, которые:
		// едут в том же направлении, между нами и ближайшим запросом с этажа;
		// либо едут в противоположном направлении, с другой стороны от запроса с этажа
		elev_betweenUp = elev_betweenDown = false;
		elev_oppositeUp = elev_oppositeDown = false;
		currentCountElevUp = currentCountElevDown = 0;
		 // проверяем каждый лифт
		for (i = 0; i < COUNT_CABINES; i++)              
		{
			// если это не нужный лифт
			if (i != m_elevNumber)                        
			{
				//  получить его этаж и направление
				floor = m_ptrBuilding->get_elevFloor(i);
				direction = m_ptrBuilding->get_elevDir(i); 

				// если этот лифт направляется вверх и сверху есть запросы с этажей,
				if ((direction == dUP || direction == dSTOP) && requests_above)
				{
					// если он при этом между нами и запросом с этажа,
					if ((floor > m_currentFloor && floor <= nearest_high_request)
						// или он на нашем этаже, но его номер меньше нашего,
						|| (floor == m_currentFloor && i < m_elevNumber))
						elev_betweenUp = true;

					if (floor > m_currentFloor
						|| (floor == m_currentFloor && i < m_elevNumber))
						currentCountElevUp++;
				}

				// если этот лифт направляется вниз и снизу есть запросы с этажей,
				if ((direction == dDOWN || direction == dSTOP) && requests_below)
				{
					// если он при этом между нами и запросом с этажа,
					if ((floor < m_currentFloor && floor >= nearest_low_request)
						// или он на нашем этаже, но его номер меньше нашего,
						|| (floor == m_currentFloor && i < m_elevNumber))
						elev_betweenDown = true;
				
					if (floor < m_currentFloor
						|| (floor == m_currentFloor && i < m_elevNumber))
						currentCountElevDown++;
				}

				// если этот лифт направляется вверх и снизу есть запросы с этажей,
				if ((direction == dUP || direction == dSTOP) && requests_below)
					// если он при этом ниже запроса с этажа и ближе к нему, чем мы,
					if (nearest_low_request >= floor
						&& nearest_low_request - floor < m_currentFloor - nearest_low_request)
					{
						elev_oppositeUp = true;
						currentCountElevDown++;
					}

				// если этот лифт направляется вниз и сверху есть запросы с этажей,
				if ((direction == dDOWN || direction == dSTOP) && requests_above)
					// если он при этом выше запроса с этажа и ближе к нему, чем мы,
					if (floor >= nearest_high_request
						&& floor - nearest_high_request < nearest_high_request - m_currentFloor)
					{
						elev_oppositeDown = true;
						currentCountElevUp++;
					}
			}
		}

		// если мы едем вверх или остановились, а выше нас есть запрос с этажа
		// и между нами и запросом с этажа нет едущих вверх лифтов
		// и нет лифтов, едущих вниз над запросом с этажа и находящихся ближе к нему, чем мы,
		if ((m_currentDir == dUP || m_currentDir == dSTOP)
			&& requests_above && !elev_betweenUp && !elev_betweenDown)
		{
			m_currentDir = dUP; // то ехать вверх
			return;           // завершить процесс принятия решения
		}

		// если мы едем вниз или остановились, а ниже нас есть запрос с этажа
		// и между нами и запросом с этажа нет едущих вниз лифтов
		// и нет лифтов, едущих вверх под запросом с этажа и находящихся ближе к нему, чем мы,
		if ((m_currentDir == dDOWN || m_currentDir == dSTOP)
			&& requests_below && !elev_betweenDown && !elev_oppositeDown)
		{
			m_currentDir = dDOWN; // то ехать вниз
			return;           // завершить процесс принятия решения
		}

		// если лифт едет вверх или стоит, есть запросы сверху,
		// и между нами и запросом с этажа есть едущие вверх лифты
		// или есть лифты, едущие вниз над запросом с этажа и находящиеся ближе к нему, чем мы,
		// и количество этих лифтов меньше количества запросов с этажей сверху,
		// то движемся ВВЕРХ
		if ((m_currentDir == dUP || m_currentDir == dSTOP)
			&& requests_above && (elev_betweenUp || elev_oppositeUp)
			&& currentCountElevUp < count_req_above)
		{
			m_currentDir = dUP; // то ехать вверх
			return;           // завершить процесс принятия решения
		}

		// если лифт едет вниз или стоит, есть запросы снизу,
		// и между нами и запросом с этажа есть едущие вниз лифты
		// или есть лифты, едущие вверх под запросом с этажа и находящиеся ближе к нему, чем мы,
		// и количество этих лифтов меньше количества запросов с этажей снизу,
		// то движемся ВНИЗ
		if ((m_currentDir == dDOWN || m_currentDir == dSTOP)
			&& requests_below && (elev_betweenDown || elev_oppositeUp)
			&& currentCountElevDown < count_req_below)
		{
			m_currentDir = dDOWN; // то ехать вниз
			return;           // завершить процесс принятия решения
		}

		m_currentDir = dSTOP;
	}

	void Elevator::get_destination()
	{
		char tempString[BUFFER_LENGTH];
		int dest_floor;

		set_cursor_pos(1, 22); clear_line();
		set_cursor_pos(1, 22);
		std::cout << "Лифт" << (m_elevNumber + 1) << "остановился на этаже " << (m_currentFloor + 1) << "...";

		for (int i = 1; i < COUNT_FLOORS; i++){

			set_cursor_pos(1, 24);
			std::cout << "Введите"<<i<<" этаж назначения: ";

			std::cin.get(tempString, BUFFER_LENGTH);
			std::cin.ignore(10, '\n');
			// этажи нумеруются с 0, а не с 1
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

			// если выбрали текущий этаж,
			if (dest_floor == m_currentFloor)
			{
				--i;
				continue;
			}

			// Есди лифт стоял, выбор этажа назначения выбирает направление движения
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