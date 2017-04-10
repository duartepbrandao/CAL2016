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
	return status && (capacity > load);
}

int Road::getCapacity() const
{
	return capacity;
}

int Road::getDistance() const
{
	return distance;
}

int Road::getLoad() const
{
	return load;
}

void Road::addCar()
{
	load++;
}

void Road::removeCar()
{
	load--;
}

void Road::setLoad(int l)
{
	load = l;
}

void Road::setStatus(bool status)
{
	this->status = status;
}

bool Road::isFull()
{
	return (capacity <= load);
}

int Road::nextID = 0;

Road::Road(int idFrom, int idTo, int roadLength, int roadCap) {
	this->ID = nextID;
	nextID++;
    load=0;
	this->idFrom=idFrom;
	this->idTo=idTo;
	this->distance=roadLength;
	this->capacity=roadCap;
	this->status = true;
}

int Road::getDestiny() {
	return idTo;
}
