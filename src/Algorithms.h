//
// Created by Duarte on 12-May-17.
//

#ifndef CAL2016_ALGORITHMS_H
#define CAL2016_ALGORITHMS_H


#include <string>
#include <vector>
#include "Exit.h"
#include <algorithm>
class Algorithms {

public:
    Algorithms();

    int exact_match(std::string input, std::vector<Exit *> exits);
};


#endif //CAL2016_ALGORITHMS_H