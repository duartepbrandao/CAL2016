#include "Car.h"



Car::Car()
{
}


Car::~Car()
{
}

int Car::nextID = 0;

Car::Car(int ID, int origin, int destiny)
{
	this->ID = ID;
	this->destiny = destiny;
	this->origin = origin;
	this->nextID = ++ID;
}

int Car::getID()
{
	return ID;
}

int Car::getDestiny()
{
	return destiny;
}

int Car::getOrigin()
{
	return origin;
}

Car::Car(int origin, int destiny) {
	this->ID = nextID;
	this->destiny = destiny;
	this->origin = origin;
	this->nextID = ID+1;
}