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

int Road::nextID = 0;

Road::Road(int ID, int idFrom, int idTo, int roadLength, int roadCap) {
this->ID = ID;
	this->idFrom=idFrom;
	this->idTo=idTo;
	this->distance=roadLength;
	this->capacity=roadCap;
	this->status = true;
}
