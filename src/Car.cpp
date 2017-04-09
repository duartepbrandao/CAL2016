#include "Car.h"



Car::Car()
{
}


Car::~Car()
{
}

Car::Car(int ID, int origin, int destiny)
{
	this->ID = ID;
	this->destiny = destiny;
	this->origin = origin;
	this->actualPosition = origin;
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

int Car::getActualPosition()
{
	return actualPosition;
}

void Car::setActualPosition(int newPosition)
{
	actualPosition = newPosition;
}

int Car::nextID = 0;
