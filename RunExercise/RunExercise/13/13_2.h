// Моделирование лифтовой системы для здания
#pragma once

#ifndef _ELEVATOR_H_
#define _ELEVATOR_H_
#endif // !_ELEVATOR_H_


#include "13_2app.h"
#include "../msoftcon.h"

#include <iostream>
#include <iomanip>

#define _CRT_SECURE_NO_WARNINGS

enum EDirection{
	dUP, dDOWN, dSTOP
};


const int LOAD_TIME = 3;	// время посадки/высадки пассажира в/из лифта(ticks)
const int SPACE = 7;		// расстояние между кабинами лифтов (в символах)
const int BUFFER_LENGTH = 80; // длина буфера вспомогательной строки


class Building;

// Класс лифта, описывающий как работает лифт. 
// Понятие слов Elevator = Cabine of elevator
class Elevator
{
public:
	Elevator(Building *build);

	void chooseAction();		// Выбор действия
	void move();				// Движение кабины лифта
	void display();			    // Отображение лифта на экране

	void floor_display() const;		// Отображение этажа(куда едет лифт)
	void decideAction();			// Принять решение о следующем действии

	void get_destination();			// Получение конечнего этажа
	int get_floor() const;			// Получение текущего этажа
	EDirection get_direction() const; // Получение текущего направления

private:
	Building *m_ptrBuilding;
	EDirection m_currentDir;	// Текущее направление движения

	int m_currentFloor;		// Текущий этаж
	int m_oldFloor;			// С какого этажа приехали
	int m_timerLoad;		// Время загрузки пассажира в лифт
	int m_timerUnload;		// Время выгрузки пассажира из лифта

	bool destination[COUNT_FLOORS];  // Этаж на который едет пассажир
};

class Building
{
public:
	Building();
	~Building();

	// Запуск лифта
	void elevator_start();  
	
	// Найти этаж с лифтом 
	int get_elevFloor() const;  
	// Получить направление лифта
	EDirection get_elevDir() const;  

	// Проверить, есть ли запрос лифта с этажа
	bool get_floorRequest(const int, const int) const;  
	// Ответить на запрос лифта с этажа
	void set_floorRequest(const int, const int, const bool); 

	// Получить запрос от пассажиров с этажей
	void record_floorRequest();  
	// Отобразить на экране запрос от пассажиров с этажей 
	void display_floorRequest() const; 

	using enum EDirection;
private:
	Elevator *m_elevator;
	// массив кнопок вызова лифта «вверх/вниз»
	// (false = ВВЕРХ, true = ВНИЗ)
	bool m_floorRequests[2][COUNT_FLOORS]; 
};