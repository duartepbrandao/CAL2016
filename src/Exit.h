#pragma once
#include <vector>
#include <string>
#include <map>
#include "Road.h"

using namespace std;

class Exit
{
private:
	static int nextID;

	int id;
    //maped with the road destiny
	std::map <int,Road*> connections;
	std::string name;
    vector<Car*> cars;


public:
	Exit();
    Exit(int ID, string name);
	~Exit();

	string getName();
	std::map<int,Road*> getConnections;
	int getID();
	void addRoad(Road* connection);
    void addCar(Car* car);
    vector<Car*> getCars() const;

};

