#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <assert.h>
#include <algorithm>
#include <limits.h>
#include <set>
#include "Exit.h"
#include "RoadNetwork.h"


bool moreCuts();

void cutRoadInput();

using namespace std;

bool RoadNetwork::readRoads() {
    ifstream inFile;

    //Ler o ficheiro roads.txt
    inFile.open("roads.txt");

    if (!inFile) {
        cerr << "Unable to open file datafile.txt";
        return false;
    }
    std::string line;
    int idFrom = 0;
    int idTo = 0;
    int roadLength = 0;
    int roadCap = 0;
    getline(inFile, line);

    while (std::getline(inFile, line)) {

        std::stringstream linestream(line);
        std::string data;

        linestream >> idFrom;
        std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
        linestream >> idTo;
        std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
        linestream >> roadLength;
        std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
        linestream >> roadCap;

        Road *newRoad = new Road(idFrom, idTo, roadLength, roadCap);

        Road *newRoad1 = new Road(idTo, idFrom, roadLength, roadCap);
        exits[idFrom]->addRoad(newRoad);
        exits[idTo]->addRoad(newRoad1);
    }
    inFile.close();
    return true;
}

bool RoadNetwork::readCars() {
    ifstream inFile;

    //Ler o ficheiro roads.txt
    inFile.open("cars.txt");

    if (!inFile) {
        cerr << "Unable to open file datafile.txt";
        return false;
    }
    std::string line;
    int idCar = 0;
    int origin = 0;
    int destiny = 0;
    getline(inFile, line);

    while (std::getline(inFile, line)) {
        std::stringstream linestream(line);
        std::string data;
        linestream >> idCar;
        std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
        linestream >> origin;
        std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
        linestream >> destiny;

        Car *newCar = new Car(idCar, origin, destiny);
        cars.push_back(newCar);
    }

    inFile.close();
    return true;
}

bool RoadNetwork::readFiles() {
    if (readExits()) {
        if (readRoads()) {

            return readCars();
        } else return false;
    } else return false;
}

bool RoadNetwork::readExits() {

    ifstream inFile;

    //Ler o ficheiro nos.txt
    inFile.open("exits.txt");

    if (!inFile) {
        cerr << "Unable to open file datafile.txt";
        return false;
    }
    std::string line;
    int idNo = 0;
    string name;
    getline(inFile, line);

    while (std::getline(inFile, line)) {
        std::stringstream linestream(line);
        std::string data;
        linestream >> idNo;
        std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
        linestream >> name;
        Exit *exitRead = new Exit(idNo, name);
        exits.push_back(exitRead);
    }

    inFile.close();
    return true;
}

void RoadNetwork::cutRoad(int from, int to) {

    for (vector<Road *>::iterator it = exits[from]->getConnections().begin();
         it != exits[from]->getConnections().end();
         ++it) {
        if ((*it)->getDestiny() == to) {
            (*it)->setStatus(false);
        }
    }
}


bool moreCuts() {
    cout << "Do you wish to make more road cuts? (Y/N)" << endl;
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    if (s.compare("y")) {
        return false;
    }
    return true;
}

//returns the path distance and you can get the Exits ID's in pathExit
int RoadNetwork::dijkstra(vector<Exit *> graph, int start, int end,vector<int>& pathExit) {
    vector<int> min_distance(graph.size(), INT_MAX);
    min_distance[start] = 0;
    std::set<pair<int, Exit *>> vertices;
    vertices.insert(make_pair(0, graph[start]));

    pathExit.resize(graph.size(),-1);

    while (!vertices.empty()) {
        int where = vertices.begin()->second->getID();
        if (where == end) {
            return min_distance[where];
        }
        vertices.erase(vertices.begin());
        for (auto ed : graph[where]->getConnections()) {
            if (min_distance[ed->getDestiny()] > min_distance[where] + ed->getDistance()) {

                vertices.erase({min_distance[ed->getDestiny()], graph[ed->getDestiny()]});
                min_distance[ed->getDestiny()] = min_distance[where] + ed->getDistance();
                vertices.insert({min_distance[ed->getDestiny()], graph[ed->getDestiny()]});
                pathExit[ed->getDestiny()]=where;
            }
        }
    }
    return INT_MAX;
}

const vector<Exit *> &RoadNetwork::getExits() const {
    return exits;
}

RoadNetwork::RoadNetwork() {}

RoadNetwork::~RoadNetwork() {

}

void RoadNetwork::printPath(int vertex, vector<int> &previous) {
    for ( ; vertex != -1; vertex = previous[vertex])
       cout<<vertex<<"<";
}


int main(int argc, char *argv[]) {
    //read all files
    RoadNetwork network;

    network.readExits();
    network.readRoads();

    bool br = true;

    /*
    int from, to;
    do {
        cout << "Which Roads do you want to cut? (From:To)" << endl;
        cout << "From:";
        cin >> from;
        cout << "To:";
        cin >> to;
        network->cutRoad(from, to);
        br = moreCuts();
    } while (br);
*/
    //fazer o mambo
    vector<int> path;
    network.dijkstra(network.getExits(), 2, 4, path);

    network.printPath(4,path);


    return 1;
}