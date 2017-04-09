#include "Exit.h"



Exit::Exit()
{
}


Exit::~Exit()
{
}

std::string Exit::getName()
{
	return name;
}

int Exit::getID()
{
	return id;
}

void Exit::addRoad(Road* connection)
{
	connections[connection->getDestiny()]=connection;
}

int Exit::nextID = 0;

Exit::Exit(int ID, string name) {
this->id = ID;
	this->name=name;
}

void Exit::addCar(Car* car)
{
    cars.push_back(car);
}

std::vector<Car*> Exit::getCars() const
{
    return cars;
}