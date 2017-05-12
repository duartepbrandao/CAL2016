//
// Created by Duarte on 12-May-17.
//

#include <iostream>
#include "Algorithms.h"

Algorithms::Algorithms() {

}

int Algorithms::exact_match(std::string input, vector<Exit*> exits) {
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    for (int i = 0; i <exits.size() ; ++i) {
        if (input.compare(exits[i]->getLowerCaseName()) == 0){
            return exits[i]->getID();
        }
    }
    return -1;
}
