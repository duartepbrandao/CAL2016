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

    int levenshtein(std::string input, std::string comparison);
    int aproximated_match(std::string input, vector<Exit*> exits);
    vector<Exit *> exact_match(std::string input, std::vector<Exit *> exits);
    vector<int> computePrefix(string basic_string);
    vector<Exit *> aproximated_match(string start, string end);

    int exact_compare(string input, string name);

    void printResults(vector<Exit *> results);
};


#endif //CAL2016_ALGORITHMS_H
