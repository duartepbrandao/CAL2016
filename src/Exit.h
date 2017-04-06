#pragma once
#include <vector>
#include <string>
#include "Road.h"

using namespace std;

class Exit
{
private:
	static int nextID;

	int id;
	std::vector <Road> connections;
	std::string name;

public:
	Exit();
    Exit(int ID, string name);
	~Exit();

	string getName();
	std::vector<Road> getConnections;
	int getID();
	void addConnection(Road* connection);
};

