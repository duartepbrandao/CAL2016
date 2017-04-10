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



int Car::nextID = 0;
