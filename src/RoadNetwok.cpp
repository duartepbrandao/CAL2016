#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <assert.h>
#include <algorithm>
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
    int idRoad = 0;
    int idFrom = 0;
    int idTo = 0;
    int roadLength = 0;
    int roadCap = 0;
    getline(inFile, line);

    while (std::getline(inFile, line)) {
        std::stringstream linestream(line);
        std::string data;
        linestream >> idRoad;
        std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
        linestream >> idFrom;
        std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
        linestream >> idTo;
        std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
        linestream >> roadLength;
        std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
        linestream >> roadCap;


        Road *newRoad = new Road(idFrom, idTo, roadLength, roadCap);
        Road *newRoad1 = new Road(idTo, idFrom, roadLength, roadCap);
        map<int, Exit *>::iterator i = exits.find(idFrom);
        map<int, Exit *>::iterator i1 = exits.find(idTo);
        if (i != exits.end()) {
            i->second->addRoad(newRoad);
            if (i1 != exits.end()) {
                i1->second->addRoad(newRoad1);
            } else return false;
        } else return false;
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
        exits[idNo] = exitRead;
    }

    inFile.close();
    return true;
}

void RoadNetwork::cutRoad(int from, int to) {
    map<int, Exit *>::iterator i = exits.find(from);

    if (i != exits.end()) {
        map<int, Road *>::iterator i2 =
                i->second->getConnections.find(to);
        i2->second->setStatus(false);

    }
}


int main(int argc, char *argv[]) {
    //read all files
    RoadNetwork *network = new RoadNetwork();
    network->readFiles();

    bool br = true;

    int from,to;
    do {
        cout << "Which Roads do you want to cut? (From:To)"<<endl;
        cout<<"From:";
        cin>> from;
        cout<<"To:";
        cin>> to;
        network->cutRoad(from, to);
        br = moreCuts();
    } while (br);

    //fazer o mambo



    return 1;
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
