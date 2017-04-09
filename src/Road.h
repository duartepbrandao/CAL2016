#pragma once
#include <vector>
#include "Car.h"

using namespace std;

class Road
{
private:
	static int nextID;

	int ID;
	bool status;
	int idFrom,idTo;
	int capacity;
	int distance;

public:
	Road();
	~Road();
	int getID() const;
	bool getStatus() const;
	int getCapacity() const;
	int getDistance() const;
int	getDestiny();

	void setStatus(bool status);


	Road(int idFrom, int idTo, int roadLength, int roadCap);
};
