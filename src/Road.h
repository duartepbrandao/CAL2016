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
	int load;

public:
	Road();
	~Road();
	int getID() const;
	bool getStatus() const;
	int getCapacity() const;
	int getDistance() const;
	int getLoad() const;
	
	int getDestiny();
	bool isFull();

	void setStatus(bool status);
	void setLoad(int l);
	void addCar();
	void removeCar();


	Road(int idFrom, int idTo, int roadLength, int roadCap);
};
