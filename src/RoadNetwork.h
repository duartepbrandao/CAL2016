//
// Created by Duarte on 06-Apr-17.
//

#ifndef CAL2016_ROADNETWORK_H
#define CAL2016_ROADNETWORK_H


#include <map>
#include "Exit.h"

class RoadNetwork{
private:
map<int,Exit*> exits;
    vector<Car*> cars;

public:
    bool readFiles();
    bool readExits();
    bool readRoads();
    bool readCars();
    //vector<Exit *> getExits();
    RoadNetwork();
    ~RoadNetwork();



};




#endif //CAL2016_ROADNETWORK_H
