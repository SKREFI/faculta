//
// Created by skrefi on 04.04.2020.
//

#ifndef T2E17_TOOLS_H
#define T2E17_TOOLS_H

#include <bits/stdc++.h>

using namespace std;

int getRandom(int min, int max);

vector<string> split(string s, string delimiter = " ");

vector<int> range(int stop);

vector<int> range(int start, int stop);

vector<int> range(int start, int stop, int step);

template<class T>
T get(string prompt) {
    cout << prompt;
    T ret;
    cin >> ret;
    return ret;
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "V";
    os << v.size();
    os << ": [";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1) os << ", ";
    }
    os << "]";
    return os;
}

template<class T>
vector<T> extend(vector<T> v, vector<T> w){
    v.reserve(v.size() + distance(w.begin(), w.end()));
    v.insert(v.end(), w.begin(), w.end());
    return v;
}
// HELP
namespace Tools {
    template<class T>
    void print(T ret = "\n", string sep = "", string end = "\n") {
        cout << ret << sep << end;
    }
}

template<typename T, typename S>
ostream &operator<<(ostream &out, const pair<T, S> &v) {
    out << "(";
    out << v.first << ", " << v.second << ")";
    return out;
}

void my_exit();


#endif //T2E17_TOOLS_H
