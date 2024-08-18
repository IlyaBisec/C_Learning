// ������������� �������� ������� ��� ������
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


const int LOAD_TIME = 3;	// ����� �������/������� ��������� �/�� �����(ticks)
const int SPACE = 7;		// ���������� ����� �������� ������ (� ��������)
const int BUFFER_LENGTH = 80; // ����� ������ ��������������� ������


class Building;

// ����� �����, ����������� ��� �������� ����. 
// ������� ���� Elevator = Cabine of elevator
class Elevator
{
public:
	Elevator(Building *build);

	void chooseAction();		// ����� ��������
	void move();				// �������� ������ �����
	void display();			    // ����������� ����� �� ������

	void floor_display() const;		// ����������� �����(���� ���� ����)
	void decideAction();			// ������� ������� � ��������� ��������

	void get_destination();			// ��������� ��������� �����
	int get_floor() const;			// ��������� �������� �����
	EDirection get_direction() const; // ��������� �������� �����������

private:
	Building *m_ptrBuilding;
	EDirection m_currentDir;	// ������� ����������� ��������

	int m_currentFloor;		// ������� ����
	int m_oldFloor;			// � ������ ����� ��������
	int m_timerLoad;		// ����� �������� ��������� � ����
	int m_timerUnload;		// ����� �������� ��������� �� �����

	bool destination[COUNT_FLOORS];  // ���� �� ������� ���� ��������
};

class Building
{
public:
	Building();
	~Building();

	// ������ �����
	void elevator_start();  
	
	// ����� ���� � ������ 
	int get_elevFloor() const;  
	// �������� ����������� �����
	EDirection get_elevDir() const;  

	// ���������, ���� �� ������ ����� � �����
	bool get_floorRequest(const int, const int) const;  
	// �������� �� ������ ����� � �����
	void set_floorRequest(const int, const int, const bool); 

	// �������� ������ �� ���������� � ������
	void record_floorRequest();  
	// ���������� �� ������ ������ �� ���������� � ������ 
	void display_floorRequest() const; 

	using enum EDirection;
private:
	Elevator *m_elevator;
	// ������ ������ ������ ����� ������/����
	// (false = �����, true = ����)
	bool m_floorRequests[2][COUNT_FLOORS]; 
};