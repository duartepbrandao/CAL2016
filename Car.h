#pragma once
class Car
{
private:
	static int nextID;

	int ID;
	int destiny; //exit
	int origin;
	int actualPosition;
public:
	Car();
	~Car();
	Car(int ID, int origin, int destiny, int actualPosition);
	int getID();
	int getDestiny();
	int getOrigin();
	int getActualPosition();
	void setActualPosition(int);
};
