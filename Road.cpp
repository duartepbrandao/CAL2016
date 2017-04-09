#include "Road.h"
#include "Lane.h"


Road::Road()
{
}


Road::~Road()
{
}

int Road::getID()
{
	return ID;
}

int Road::getStatus(int destID)
{
	if (this->lanes.first.getDestID() == destID)
		return this->lanes.first.getStatus();
	else
		return this->lanes.second.getStatus();
}

int Road::getCapacity(int id)
{
	return 0;
}

int Road::getDistance()
{
	return length;
}

int Road::nextID = 0;

Road::Road(int ID, int idFrom, int idTo, int roadLength, int roadCap) {
/*this->ID = ID;
	this->idFrom=idFrom;
	this->idTo=idTo;
	this->distance=roadLength;
	this->capacity=roadCap;
	this->status = true;*/
}
