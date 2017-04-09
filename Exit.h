#pragma once

#include <vector>
#include <string>

class Road;
class Car;

class Exit
{
private:
	static int nextID;

	int id;
	std::vector <Road*> connections;
	std::string name;
    std::vector<Car*> cars;


public:
	Exit();
    Exit(int ID, std::string name);
	~Exit();

	std::string getName();
	std::vector<Road*> getConnections;
	int getID();
	void addRoad(Road* connection);
    void addCar(Car* car);
    std::vector<Car*> getCars() const;
};

