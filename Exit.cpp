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
	return ID;
}

void Exit::addConnection(Road connection)
{
	connections.push_back(connection);
}

int Exit::nextID = 0;
