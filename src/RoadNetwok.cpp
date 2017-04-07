#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <assert.h>
#include "Exit.h"
#include "RoadNetwork.h"


using namespace std;

bool RoadNetwork::readRoads() {
    ifstream inFile;

    //Ler o ficheiro roads.txt
    inFile.open("roads.txt");

    if (!inFile) {
        cerr << "Unable to open file datafile.txt";
        return false;
    }
    std::string   line;
    int idRoad=0;
    int idFrom=0;
    int idTo=0;
    int roadLength=0;
    int roadCap=0;
    bool roadStatus;
    getline(inFile,line);

    while(std::getline(inFile, line))
    {
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
        std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
        linestream >> roadStatus;

        Road* newRoad = new Road(idRoad,idFrom,idTo,roadLength,roadCap,roadStatus);
        map<int,Exit*>::iterator i = exits.find(idFrom);
        if(i != exits.end()){
            i->second->addRoad(newRoad);
        }else return false;
    }

    inFile.close();
    return true;
}

bool RoadNetwork::readCars() { ifstream inFile;

    //Ler o ficheiro roads.txt
    inFile.open("cars.txt");

    if (!inFile) {
        cerr << "Unable to open file datafile.txt";
        return false;
    }
    std::string   line;
    int idCar=0;
    int origin=0;
    int destiny=0;
    getline(inFile,line);

    while(std::getline(inFile, line))
    {
        std::stringstream linestream(line);
        std::string data;
        linestream >> idCar;
        std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
        linestream >> origin;
        std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
        linestream >> destiny;

        Car* newCar = new Car(idCar, origin,destiny);
        map<int,Exit*>::iterator i = exits.find(origin);

        if(i != exits.end()){
            i->second->addCar(newCar);
        }else return false;
    }

    inFile.close();
    return true;
}

bool RoadNetwork::readFiles() {
    if (readExits()){
        if (readRoads()){
            return readCars();
        } else return false;
    }else return false;
}

bool RoadNetwork::readExits() {

    ifstream inFile;

    //Ler o ficheiro nos.txt
    inFile.open("exits.txt");

    if (!inFile) {
        cerr << "Unable to open file datafile.txt";
        return false;
    }
    std::string   line;
    int idNo=0;
    string name;
    getline(inFile,line);

    while(std::getline(inFile, line))
    {
        std::stringstream linestream(line);
        std::string         data;
        linestream >> idNo;
        std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
        linestream >> name;
        Exit* exitRead = new Exit(idNo,name);
        exits[idNo]=exitRead;
    }

    inFile.close();
    return true;
}


int main(int argc, char* argv[])
{
    //read all files

    //fazer o mambo



    return 1;
}
