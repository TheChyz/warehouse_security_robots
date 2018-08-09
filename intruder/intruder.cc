#include "intruder.h"

unsigned int intruder;

std::vector<std::vector<unsigned int>> intruderStart(unsigned int start_intruder_position, unsigned int current_index) {
	std::vector<std::vector<unsigned int>> warehouse_with_robots;
	std::pair<unsigned int, unsigned int> intruder_position;

	if (start == 1) {
		intruder = 6;
	} 
	else if (start == 2) {
		intruder = 111;
	} 
	else if (start == 3) {
		intruder = 142;
	}
	else { // start == 4 or by default
		intruder = 263;
	}

	warehouse_with_robots = warehousePatrolUpdate(current_index);
	intruder_position = getNodeCoordinate(warehouse_big, intruder);

	// Create graph again with intruder location
	warehouse_with_robots[intruder_position.first][intruder_position.second] = 4;

}

// 1 = left, 2 = right, 3 = up, 4 = down
std::vector<std::vector<unsigned int>> intruderMove(unsigned int move) {
	std::pair<unsigned int, unsigned int> intruder_position;
	unsigned int position_count;
	unsigned int nodes_counted = 0;

	// intruder position before moving
	intruder_position = getNodeCoordinate(warehouse_big, intruder);

	// moves intruder if possible
	if (move == 1) {
		if (warehouse_big[intruder_position.first][intruder_position.second - 1] == 0) {
			intruder = intruder - 1;
		}
	}
	else if (move == 2) {
		if (warehouse_big[intruder_position.first][intruder_position.second + 1] == 0) {
			intruder = intruder + 1;
		}
	}
	else if (move == 3) {
		if (warehouse_big[intruder_position.first + 1][intruder_position.second] == 0) {
			for (position_count = 1; position_count <= 30; position_count++) {
				if (intruder_position.second - position_count < 0) {
					if (warehouse_big[intruder_position.first - 1][intruder_position.second - (position_count % 30)] == 0) {
						nodes_counted++;
					}
				} else {
					if (warehouse_big[intruder_position.first][intruder_position.second - position_count] == 0) {
						nodes_counted++;
					}
				}
			}
		}
		intruder = intruder - nodes_counted;
	}
	else if (move == 4) {
		if (warehouse_big[intruder_position.first - 1][intruder_position.second] == 0) {
			for (position_count = 1; position_count <= 30; position_count++) {
				if (intruder_position.second + position_count > 29) {
					if (warehouse_big[intruder_position.first + 1][intruder_position.second + (position_count % 30)] == 0) {
						nodes_counted++;
					}
				} else {
					if (warehouse_big[intruder_position.first][intruder_position.second + position_count] == 0) {
						nodes_counted++;
					}
				}
			}
		}
		intruder = intruder - nodes_counted;
	}

	// intruder position after moving
	intruder_position = getNodeCoordinate(warehouse_big, intruder);

	// Create graph again with updated intruder location
	warehouse_with_robots[intruder_position.first][intruder_position.second] = 4;

}


bool intruderFound() {
	return false;
}