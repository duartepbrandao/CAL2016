#pragma once


#include <list>

class Car
{
private:
	static int nextID;

	int ID;
	int destiny; //exit
	int origin;
public:

    std::list<int> path;
	Car();
	~Car();
	Car(int ID, int origin, int destiny);
	int getID();
	int getDestiny();
	int getOrigin();
    void setPath(std::list<int>);
};

