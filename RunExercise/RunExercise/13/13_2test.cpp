#include <iostream>
#include <cassert>
#include "13_2.h"

// Checking results
void test_building_constructor() {
    Building building;

    for (int i = 0; i < NUM_FLOORS; i++) {
        assert(!building.get_floorRequest(dUP, i) && "Error: The request for the dUP floor should not be set");
        assert(!building.get_floorRequest(dDOWN, i) && "Error: The down floor request should not be set");
    }
    std::cout << "test_building_constructor passed\n";
}

void test_add_floor_request() {
    Building building;

    building.set_floorRequest(dUP, 5, true);
    assert(building.get_floorRequest(dUP, 5) && "Error: The request for the dUP floor is not set correctly");

    building.set_floorRequest(dDOWN, 8, true);
    assert(building.get_floorRequest(dDOWN, 8) && "Error: The request for the down floor is not set correctly");

    std::cout << "test_add_floor_request passed\n";
}

void test_elevator_initial_state() {
    Building building;
    Elevator elevator(&building, 0);

    assert(elevator.get_floor() == 0 && "Error: the initial floor of the elevator should be 0");
    assert(elevator.get_direction() == dSTOP && "Error: the initial direction of the elevator should be STOP");

    std::cout << "test_elevator_initial_state passed\n";
}

void test_elevator_move_up() {
    Building building;
    Elevator elevator(&building, 0);

    building.set_floorRequest(dUP, 2, true);
    elevator.elevatorTick(); // The elevator is moving
    elevator.elevatorTick2(); // The elevator handles the movement

    assert(elevator.get_floor() == 1 && "Error: the elevator must be on the 1st floor");
    assert(elevator.get_direction() == dUP && "Error: the direction of the elevator should be UP");

    std::cout << "test_elevator_move_up passed\n";
}

void test_elevator_move_down() {
    Building building;
    Elevator elevator(&building, 2);

    building.set_floorRequest(dDOWN, 0, true);
    elevator.elevatorTick(); // The elevator is moving
    elevator.elevatorTick2(); // The elevator handles the movement

    assert(elevator.get_floor() == 1 && "Error: the elevator must be on the 1st floor");
    assert(elevator.get_direction() == dDOWN && "Error: the direction of the elevator should be DOWN");

    std::cout << "test_elevator_move_down passed\n";
}

void test_elevator_stop() {
    Building building;
    Elevator elevator(&building, 0);

    elevator.elevatorTick(); // The elevator is in standby mode
    assert(elevator.get_direction() == dSTOP && "Error: the elevator must be able to STOP");

    std::cout << "test_elevator_stop passed\n";
}

// The main function for running all tests
int main13_22() {
    test_building_constructor();
    test_add_floor_request();
    test_elevator_initial_state();
    test_elevator_move_up();
    test_elevator_move_down();
    test_elevator_stop();

    std::cout << "All tests have been successfully passed!\n";
    return 0;
}
