#pragma once

class Road
{
private:
	int ID;
	static int nextID;
public:
	Road();
	~Road();
};

Road::nextID = 0;

