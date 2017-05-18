//
// Created by Duarte on 12-May-17.
//

#include <iostream>
#include "Algorithms.h"


Algorithms::Algorithms() {

}

bool Algorithms::exact_compare(std::string input, std::string name) {
    int inputLength = input.length();
    int nameLength = name.length();
    //vector<int> a = computePrefix(input);
    bool match = false;


}

vector<int> Algorithms::computePrefix(string pattern) {
    int m = pattern.length();
    vector <int> q;
    q.push_back(-1);
    int k = 0;
    int pos = 1;
    while (pos < m-1){
        if (pattern[pos] == pattern[k] ){
            q.push_back(q[k]);
            pos++;
            k++;
        } else{
            q.push_back(k);
            k=q[k];
            while (k>= 0 && pattern[pos] !=pattern[k]){
                k=q[k];
            }
            pos++;
            k++;
        }
    }
    q.push_back(k);

    return q;
}

int Algorithms::exact_match(std::string input, vector<Exit *> exits) {
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    for (int i = 0; i < exits.size(); ++i) {
        if (input.compare(exits[i]->getLowerCaseName()) == 0) {
            return exits[i]->getID();
        }
    }
    return -1;
}

