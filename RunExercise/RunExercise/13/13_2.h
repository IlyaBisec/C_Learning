// Modeling of an elevator system for a building
#define _CRT_SECURE_NO_WARNINGS
#pragma once

#ifndef _ELEVATOR_H_
#define _ELEVATOR_H_

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <process.h>

#include <thread>
#include <chrono>

#include "../msoftcon.h"

enum EDirection{
	
	dUP, dDOWN, dSTOP
};


constexpr int LOAD_TIME = 3;		// Passenger load/unload time in/out of the elevator
constexpr int SPACE = 7;			// Distance between elevator cabins (in symbols)
constexpr int BUFFER_LENGTH = 80;	// Buffer length of the auxiliary string

constexpr int NUM_FLOORS = 10;		// Number of floors
constexpr int NUM_CABINES = 1;			// Number of elevatror cabines 

// Clear the selected area
// x, yMin, yMax - coordinates
// time - the time after which the field is cleared  
void clearMsgLines(int x, int yMin, int yMax, int time);

class Building;

// An elevator class that describes how the elevator works. 
// The position of the words Elevator = Elevator cabine
class Elevator
{
public:
	Elevator(Building *build, int);

	void elevatorTick();		// Metromome-1 for every elevator cabine
	void elevatorTick2();		// Metromome-2 for every elevator cabine

	void move();				// Movement of the elevator cabin
	void display();			    // Elevator display on the screen

	void floor_display() const;		// Displaying the floor (where the elevator goes)
	void decideAction();			// Decide on the next action

	void get_destination();			// Getting the final floor
	int get_floor() const;			// Getting the current floor
	EDirection get_direction() const; // Getting the current direction

private:
	Building *m_ptrBuilding;
	EDirection m_currentDir;	// Current direction of move

	const int m_cabineNumber; // Cabine number(0 to nc-1)

	int m_currentFloor;		// Current floor(0 to nf-1)
	int m_oldFloor;			// What floor did you come from (0 to nf-1)

	int m_timerLoad;		// Passenger loading time in the elevator
	int m_timerUnload;		// The time of unloading the passenger from the elevator

	bool destination[NUM_FLOORS];  // The floor to which the passenger is moving
};
		
// The class of the building that has an elevator
class Building
{
public:
	Building();
	~Building();

	// Starting the elevator, master_tick()
	void elevator_start();

	// Find a floor number with an elevator
	int get_elevFloor(const int) const;
	// Get the direction of the elevator
	EDirection get_elevDir(const int) const;

	// Check if there is a request for an elevator from the floor
	bool get_floorRequest(const int, const int) const;
	// To respond to the request for an elevator from the floor
	void set_floorRequest(const int, const int, const bool);

	// Receive a request from passengers from the floors
	void record_floorRequest();
	// Display a request from passengers from the floors on the screen
	void display_floorRequest() const;

private:
	Elevator *m_cabineList[NUM_CABINES];
	int m_currNumCabines;

	// Array of elevator call buttons "up/down"
	// (false = UP, true = DOWN)
	bool m_floorRequests[2][NUM_FLOORS];
};


#endif // !_ELEVATOR_H_