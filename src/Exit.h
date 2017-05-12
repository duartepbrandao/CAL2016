#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include "Road.h"

using namespace std;

class Exit
{
private:
	static int nextID;

	int id;
    //maped with the road destiny
	vector <Road*> connections;
	std::string name;
	std::string lowerCaseName;
public:
	const string getLowerCaseName() const;

private:
	vector<Car*> cars;


public:
	Exit();
    Exit(int ID, string name);
	~Exit();

	string getName();
	vector <Road*> getConnections();
	int getID();
	void addRoad(Road* connection);
    void addCar(Car* car);
    vector<Car*> getCars() const;

};

