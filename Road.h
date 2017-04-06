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
	int capacity;
	int distance;
	vector<Car> cars;

public:
	Road();
	~Road();
	int getID() const;
	bool getStatus() const;
	int getCapacity() const;
	int getDistance() const;

	void setStatus(bool status);
	void addCar(Car car);
	vector<Car> getCars() const;
};
