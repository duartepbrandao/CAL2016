//
// Created by Duarte on 12-May-17.
//

#include <iostream>
#include "Algorithms.h"


Algorithms::Algorithms() {

}

int Algorithms::exact_compare(std::string w, std::string s) {
    int inputLength = s.length();
    int nameLength = w.length();
    vector<int> t = computePrefix(w);
    int m = 0;
    int i = 0;
    while (m + i < inputLength) {
        if (w[i] == s[m + i]) {
            i++;
            if (i == nameLength) {
                return m;
                //
            }
        } else {
            if (t[i] > -1) {
                m = m + i - t[i];
                i = t[i];
            } else {
                m = m + i + 1;
                i = 0;
            }
        }
    }
    return -1;
}


vector<int> Algorithms::computePrefix(string pattern) {
    int m = pattern.length();
    vector<int> q;
    q.push_back(-1);
    int k = 0;
    int pos = 1;
    while (pos < m - 1) {
        if (pattern[pos] == pattern[k]) {
            q.push_back(q[k]);
            pos++;
            k++;
        } else {
            q.push_back(k);
            k = q[k];
            while (k >= 0 && pattern[pos] != pattern[k]) {
                k = q[k];
            }
            pos++;
            k++;
        }
    }
    q.push_back(k);

    return q;
}

int Algorithms::levenshtein(std::string input, std::string comparison) {

    std::vector<std::vector<int>> matrix;

    matrix.resize(input.size());

    for (int i = 0; i < input.size(); i++) {
        matrix[i].resize(comparison.size());
        matrix[i][0] = i;
    }
    for (int j = 0; j < comparison.size(); j++) matrix[0][j] = j;

    for (int i = 1; i < input.size(); i++)
        for (int j = 1; j < comparison.size(); j++)
            if (input[i] == comparison[j]) matrix[i][j] = matrix[i - 1][j - 1];
            else matrix[i][j] = 1 + min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1]));

    return matrix[input.size() - 1][comparison.size() - 1];
}

int Algorithms::aproximated_match(std::string input, vector<Exit *> exits) {
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    int curMin = 999999;
    int exit = -1;
    for (int i = 0; i < exits.size(); i++) {
        int curVal = levenshtein(input, exits[i]->getLowerCaseName());
        if (curVal <= curMin) {
            curMin = curVal;
            exit = exits[i]->getID();
        }
    }
    return exit;
}

vector<Exit*> Algorithms::exact_match(std::string input, vector<Exit *> exits) {
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    vector<Exit*> results;
    for (int i = 0; i < exits.size(); ++i) {
       if( exact_compare(input,exits[i]->getLowerCaseName()) > -1){
           results.push_back(exits[i]);
        }
    }
    return results;
}

void Algorithms::printResults(vector<Exit *> results) {
    for (int i = 0; i <results.size() ; ++i) {
        cout<<i+1<<" -- " << results[i]->getName()<<endl;
    }
    cout<< "Escolha o inicio do percurso: "<<endl;
}

