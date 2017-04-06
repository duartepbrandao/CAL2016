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

void Exit::addConnection(Road connection)
{
	connections.push_back(connection);
}

int Exit::nextID = 0;

Exit::Exit(int ID, string name) {
this->id = ID;
	this->name=name;
}
