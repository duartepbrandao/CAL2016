#pragma once

#include <utility>

class Lane;

class Road
{
private:
	static int nextID;

	int ID;
	int length;
	std::pair<Lane,Lane> lanes;

public:
	Road();
	~Road();
	int getID();
	int getStatus(int ID);
	int getCapacity(int ID);
	int getDistance();

	Road(int ID, int idFrom, int idTo, int roadLength, int roadCap);
};
