#include "Car.h"
#include "Lane.h"


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
	//this->actualPosition = origin;
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

Lane * Car::getActualPosition()
{
	return actualPosition;
}

void Car::setActualPosition(Lane * newPosition)
{
	actualPosition = newPosition;
}

int Car::nextID = 0;
