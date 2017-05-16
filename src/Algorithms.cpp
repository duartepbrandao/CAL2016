//
// Created by Duarte on 12-May-17.
//

#include <iostream>
#include "Algorithms.h"

Algorithms::Algorithms() {

}

int Algorithms::levenshtein(std::string input, std::string comparison) {

    std::vector<std::vector<int>> matrix;

    matrix.resize(input.size());

    for (int i = 0; i<input.size(); i++)
        {
            matrix[i].resize(comparison.size());
            matrix[i][0] = i;
        }
    for (int j = 0; j<comparison.size(); j++) matrix[0][j] = j;

    for (int i = 1; i<input.size(); i++)
        for (int j = 1; j<comparison.size(); j++)
            if (input[i] == comparison[j]) matrix[i][j] = matrix[i-1][j-1];
            else matrix[i][j] = 1 + min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i][j-1]));

    return matrix[input.size()-1][comparison.size()-1];
}

int Algorithms::aproximated_match(std::string input, vector<Exit*> exits) {
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    int curMin = 999999;
    int exit = -1;
    for (int i = 0; i <exits.size() ; i++) {
        int curVal = levenshtein(input, exits[i]->getLowerCaseName());
        if (curVal <= curMin)
        {
            curMin = curVal;
            exit = exits[i]->getID();
        }
    }
    return exit;
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
