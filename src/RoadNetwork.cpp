#include <iostream>
#include <conio.h>
#include <winsock2.h>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <assert.h>
#include <algorithm>
#include <limits.h>
#include <set>
#include <list>
#include <unistd.h>
#include "Exit.h"
#include "graphviewer.h"
#include "RoadNetwork.h"
#include "Algorithms.h"


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
        int pos = line.find(';');
        int idNo = stoi(line.substr(0, pos));
        string name = line.substr(pos + 1, line.length());


        Exit *exitRead = new Exit(idNo, name);
        exits.push_back(exitRead);
    }

    inFile.close();
    return true;
}

void RoadNetwork::cutRoad(int from, int to) {

    for (int i = 0; i < exits[from]->getConnections().size(); ++i) {
        if (exits[from]->getConnections()[i]->getDestiny() == to) {
            exits[from]->getConnections()[i]->setStatus(false);
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
int RoadNetwork::dijkstra(vector<Exit *> graph, int start, int end, vector<int> &pathExit) {
    vector<int> min_distance(graph.size(), INT_MAX);
    min_distance[start] = 0;
    std::set<pair<int, Exit *>> vertices;
    vertices.insert(make_pair(0, graph[start]));

    pathExit.resize(graph.size(), -1);

    while (!vertices.empty()) {
        int where = vertices.begin()->second->getID();
        if (where == end) {
            return min_distance[where];
        }
        vertices.erase(vertices.begin());
        for (auto ed : graph[where]->getConnections()) {
            if (!(ed->getStatus())) continue;
            if (min_distance[ed->getDestiny()] > min_distance[where] + ed->getDistance()) {
                vertices.erase({min_distance[ed->getDestiny()], graph[ed->getDestiny()]});
                min_distance[ed->getDestiny()] = min_distance[where] + ed->getDistance();
                vertices.insert({min_distance[ed->getDestiny()], graph[ed->getDestiny()]});
                pathExit[ed->getDestiny()] = where;

            }
        }
    }
    return INT_MAX;
}

const vector<Exit *> RoadNetwork::getExits() const {
    return exits;
}

RoadNetwork::RoadNetwork() {}

RoadNetwork::~RoadNetwork() {

}

void RoadNetwork::getPath(list<int> fifth) {

    for (std::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
        std::cout << *it << ' ';

}

vector<Car *> RoadNetwork::getCars() const {
    return cars;
}

void RoadNetwork::printPath(list<int> list) {

    for (std::list<int>::iterator it = list.begin(); it != list.end(); it++) {

        int id1 = list.front();
        list.pop_front();
        if (!list.empty()) {
            int id2 = list.front();
            for (int i = 0; i < exits[id1]->getConnections().size(); ++i) {
                if (exits[id1]->getConnections()[i]->getDestiny() == id2) {
                    cout << "from " << id1 << " to " << id2 << endl;
                    gv->setEdgeColor(exits[id1]->getConnections()[i]->getID(), "green");
                }
            }
        } else
            break;
    }
}


void versionChoice() {
    cout << "Which algorithm do you want to use?" << endl;
    cout << "1-Diekstra" << endl;
    cout << "2-Aproximated match String" << endl;
    cout << "3-Exact match String" << endl;

}

void RoadNetwork::getPathbyID(int id) {
    printPath(getCars()[id]->path);

    gv->rearrange();

    Sleep(100000);
}


void RoadNetwork::regularPath() {
    cout << "Which car do you want to see the path?" << endl;
    int id;
    cin >> id;

    printPath(getCars()[id]->path);

    gv->rearrange();

    Sleep(100000);

}

void RoadNetwork::addCar(Car *car) {
    cars.push_back(car);
}

int main(int argc, char *argv[]) {
    //read all files
    RoadNetwork network;
    Algorithms algorithms;
    network.readExits();
    network.readRoads();
    network.readCars();
    bool br = true;
    int from, to;
    do {
        cout << "Which Roads do you want to cut? (From:To)" << endl;
        cout << "From:";
        cin >> from;
        cout << "To:";
        cin >> to;
        network.cutRoad(from, to);
        br = moreCuts();

    } while (br);

    //TODO:validate inputs
    bool valid_inputs = false;
    do {
        versionChoice();
        int inp;
        cin >> inp;
        cin.ignore(1000, '\n');
        if (inp == 1) {
            //TODO: make this work with the 1st project
            network.regularPath();

        } else if (inp == 2) {
            string start;
            string end;
            cout << "Onde se encontra?" << endl;

            getline(cin, start);
            int id_start = algorithms.aproximated_match(start, network.getExits());
            if (id_start != -1) {
                cout << "Melhor resultado: " << network.getExits()[id_start]->getName() << endl;
                cout << "Qual o seu destino?" << endl;
                getline(cin, end);
                int id_end = algorithms.aproximated_match(end, network.getExits());
                cout << "Melhor resultado: " << network.getExits()[id_end]->getName() << endl;
                if (id_end != -1) {
                    Car *newCar = new Car(id_start, id_end);
                    network.addCar(newCar);


                    vector<int> path;
                    network.dijkstra(network.getExits(), id_start, id_end, path);
                    for (int vertex = network.getCars()[newCar->getID()]->getDestiny();
                         vertex != -1; vertex = path[vertex]) {
                        network.getCars()[newCar->getID()]->path.push_front(vertex);
                    }
                    //print path
                    network.getPath(network.getCars()[newCar->getID()]->path);


                } else {
                    cout << "Lugar Desconhecido!!" << endl;
                }

            } else {
                cout << "Lugar Desconhecido!!" << endl;
            }
        } else if (inp == 3) {
            string start;
            string end;
            cout << "Onde se encontra?" << endl;

            getline(cin, start);
            vector<Exit *> start_results = algorithms.exact_match(start, network.getExits());

            if (start_results.size()) {
                algorithms.printResults(start_results);
                cout << "Escolha o inicio do percurso: " << endl;
                string choice;

                getline(cin, choice);
                int id_start = stoi(choice) - 1;
                cout << "Qual o seu destino?" << endl;
                getline(cin, end);
                vector<Exit *> end_results = algorithms.exact_match(end, network.getExits());
                if (end_results.size()) {

                    algorithms.printResults(end_results);

                    cout << "Escolha o destino: " << endl;
                    getline(cin, choice);

                    int id_end = stoi(choice) - 1;

                    Car *newCar = new Car(start_results[id_start]->getID(), end_results[id_end]->getID());
                    network.addCar(newCar);


                    vector<int> path;
                    cout << "from " << start_results[id_start]->getID() << " to " << end_results[id_end]->getID()
                         << endl;
                    network.dijkstra(network.getExits(), start_results[id_start]->getID(), end_results[id_end]->getID(),
                                     path);
                    for (int vertex = network.getCars()[newCar->getID()]->getDestiny();
                         vertex != -1; vertex = path[vertex]) {
                        network.getCars()[newCar->getID()]->path.push_front(vertex);
                    }
                    //print path
                    network.getPath(network.getCars()[newCar->getID()]->path);


                } else {
                    cout << "Lugar Desconhecido!!" << endl;
                }

            } else {
                cout << "Lugar Desconhecido!!" << endl;
            }
        } else {
            valid_inputs = true;
            cout << "Invalid choice!! please try again!" << endl;
        }
    } while (valid_inputs);



    //TODO: get some pretty way to make the dijkstra function

    vector<int> path;

    for (int i = 0; i < network.getCars().size(); i++) {
        path.clear();
        network.dijkstra(network.getExits(), network.getCars()[i]->getOrigin(), network.getCars()[i]->getDestiny(),
                         path);
        for (int vertex = network.getCars()[i]->getDestiny(); vertex != -1; vertex = path[vertex]) {
            network.getCars()[i]->path.push_front(vertex);
        }
    }

    network.getPath(network.getCars()[0]->path);

    network.gv = new GraphViewer(800, 800, true);
    network.gv->createWindow(800, 800);

    network.gv->defineEdgeColor("blue");
    network.gv->defineVertexColor("yellow");

    for (int i = 0; i < network.getExits().size(); i++) {

        network.gv->addNode(network.getExits()[i]->getID());
        network.gv->setVertexLabel(network.getExits()[i]->getID(), network.getExits()[i]->getName());
    }

    for (int i = 0; i < network.getExits().size(); i++) {
        for (int j = 0; j < network.getExits()[i]->getConnections().size(); ++j) {

            network.gv->addEdge(network.getExits()[i]->getConnections()[j]->getID(), i,
                                network.getExits()[i]->getConnections()[j]->getDestiny(), EdgeType::DIRECTED);
            network.gv->setEdgeLabel(network.getExits()[i]->getConnections()[j]->getID(),
                                     to_string(network.getExits()[i]->getConnections()[j]->getDistance()));

            if (network.getExits()[i]->getConnections()[j]->getStatus()) {
                network.gv->setEdgeColor(network.getExits()[i]->getConnections()[j]->getID(), "blue");
            } else {

                network.gv->setEdgeColor(network.getExits()[i]->getConnections()[j]->getID(), "red");
            }
        }

    }
    network.gv->rearrange();

    sleep(10000);
    return 1;
}
