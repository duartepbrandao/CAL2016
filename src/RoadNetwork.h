//
// Created by Duarte on 06-Apr-17.
//

#ifndef CAL2016_ROADNETWORK_H
#define CAL2016_ROADNETWORK_H


#include <map>
#include "Exit.h"

class RoadNetwork{
private:
vector<Exit*> exits;

    vector<Car*> cars;

public:
    const vector<Exit *> &getExits() const;
    bool readFiles();
    bool readExits();
    bool readRoads();
    bool readCars();
    //vector<Exit *> getExits();


    RoadNetwork();


    virtual ~RoadNetwork();

    int dijkstra(vector<Exit *> graph, int start, int end);


    void cutRoad(int from, int to);
};




#endif //CAL2016_ROADNETWORK_H
