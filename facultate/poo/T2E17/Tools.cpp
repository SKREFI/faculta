//
// Created by skrefi on 04.04.2020.
//

#include "Tools.h"
#include <bits/stdc++.h>

int getRandom(int min, int max) { return rand() % max + min; }

vector<string> split(string s, string delimiter) {
    vector<string> v;
    int old = 0;
    while (s.find(delimiter) < s.size()) {
        string token = s.substr(old, s.find(delimiter));
        v.push_back(token);

        s = s.substr(s.find(delimiter) + 1, s.size());
    }
    v.push_back(s.substr(old, s.size()));
    return v;
}

vector<int> range(int stop) {
    vector<int> ret;
    for (int i = 0; i < stop; i++) {
        ret.push_back(i);
    }
    return ret;
}

vector<int> range(int start, int stop) {
    vector<int> ret;
    for (int i = start; i < stop; i++) {
        ret.push_back(i);
    }
    return ret;
}

vector<int> range(int start, int stop, int step) {
    vector<int> ret;
    for (int i = start; i < stop; i += step) {
        ret.push_back(i);
    }
    return ret;
}

void my_exit() {
    Tools::print("\n\n__-==DONE==-__");
    exit(1);
}