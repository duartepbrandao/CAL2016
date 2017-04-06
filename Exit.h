#pragma once
#include <vector>
#include "Road.h"

using namespace std;

class Exit
{
private:
	static int nextID;

	int ID;
	std::vector <Road> connections;
	std::string name;

public:
	Exit();
	~Exit();

	std::string getName();
	std::vector<Road> getConnections;
	int getID();
	void addConnection(Road connection);
};

