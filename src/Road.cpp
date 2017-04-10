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
	return distance;
}

void Road::setStatus(bool status)
{
	this->status = status;
}

int Road::nextID = 0;

Road::Road(int idFrom, int idTo, int roadLength, int roadCap) {
	this->ID = nextID;
	nextID++;
	this->idFrom=idFrom;
	this->idTo=idTo;
	this->distance=roadLength;
	this->capacity=roadCap;
	this->status = true;
}

int Road::getDestiny() {
	return idTo;
}
