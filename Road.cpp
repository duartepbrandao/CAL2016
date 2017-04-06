#include "Road.h"



Road::Road()
{
}


Road::~Road()
{
}

int Road::getID() const
{
	return ID;
}

bool Road::getStatus() const
{
	return status;
}

int Road::getCapacity() const
{
	return capacity;
}

int Road::getDistance() const
{
	return capacity;
}

void Road::setStatus(bool status)
{
	this->status = status;
}

void Road::addCar(Car car)
{
	cars.push_back(car);
}

std::vector<Car> Road::getCars() const
{
	return cars;
}


int Road::nextID = 0;
