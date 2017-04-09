/*
 * Lane.cpp
 *
 *  Created on: Apr 8, 2017
 *      Author: ShoterXX
 */

#include "Lane.h"
#include "Car.h"
#include "Exit.h"

Lane::Lane() {
	// TODO Auto-generated constructor stub

}

Lane::~Lane() {
	// TODO Auto-generated destructor stub
}

int Lane::enterLane(Car* vehicle) {
	if (this->status) return this->status;

	if (vehicle->getActualPosition()->exitLane(vehicle)) return CAR_NOT_FOUND;

	vehicle->setActualPosition(this);

	this->load.push_back(vehicle);

	if (this->load.size() >= this->capacity) this->status |= LANE_FULL;
}

int Lane::getCapacity() {
	return this->capacity;
}

int Lane::getLoad() {
	return this->load.size();
}

int Lane::getStatus() {
	return this->status;
}

vector<Car*> Lane::getVehicles() {
	return this->load;
}

int Lane::exitLane(Car* vehicle) {

	unsigned int size = this->load.size();

	for (unsigned int i = 0; i < size; i++)
		if (vehicle == this->load[i])
		{
			this->load.erase(this->load.begin() + i);
			return 0;
		}

	this->clearObstrucion();

	return CAR_NOT_FOUND;
}

void Lane::setObstructed() {
	this->status |= LANE_OBSTRUCTED;
}

void Lane::clearObstrucion() {
	if (this->status & LANE_OBSTRUCTED)
	this->status ^= LANE_OBSTRUCTED;
}

int Lane::getDestID() {
	return this->destination->getID();
}
