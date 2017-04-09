#pragma once

using namespace std;

class Lane;

class Car
{
private:
	static int nextID;

	int ID;
	int destiny; //exit
	int origin;
	Lane * actualPosition;

public:
	Car();
	~Car();
	Car(int ID, int origin, int destiny);
	int getID();
	int getDestiny();
	int getOrigin();
	Lane * getActualPosition();
	void setActualPosition(Lane * newPosition);
};

