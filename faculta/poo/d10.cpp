#include <bits/stdc++.h>
using namespace std;

int getRandom(int min, int max) { return rand() % max + min; }
vector<int> range(int stop) {
    vector<int> ret;
    for (int i = 0; i <= stop; i++) {
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
    for (int i = start; i < stop; i + step) {
        ret.push_back(i);
    }
    return ret;
}

#define INIT_ENERGY 100

// Operator overloading pentru vectori, print vector adica :))
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1) os << ", ";
    }
    os << "]";
    return os;
}

template <class T>
void print(T print, string sep = " ", string end = "\n") {
    cout << print << sep << end;
}

class Individ {
    int i, j, varsta, fii;
    char tip;
    double energie;
    bool viu;

   public:
    Individ() {
        i = 0;
        j = 0;
        varsta = 0;
        fii = 0;
        tip = '0';
        energie = 0;
        viu = 0;
    }
    Individ(int i, int j, char tip) {
        this->i = i;
        this->j = j;
        this->tip = tip;
        this->energie = INIT_ENERGY;
        this->varsta = 0;
        this->viu = true;
    }

    int get_i() { return this->i; }
    int get_j() { return this->j; }

    friend ostream &operator<<(ostream &out, const Individ &i) {
        out << i.tip;
        return out;
    }
    // hraneste, inmuteste, ataca, imbatraneste, kill
};

class tip {
   public:
    vector<char> v{'+', '-'};
    char get(int i) { return v[i]; }
};

int main() {
    vector<vector<Individ>> m;
    tip t;

    for (auto __ : range(20)) {
        vector<Individ> line;
        for (auto __ : range(70)) line.push_back(Individ());
        m.push_back(line);
    }

    for (auto _ : range(100)) {
        Individ individ =
            Individ(getRandom(0, 20), getRandom(0, 70), t.get(getRandom(0, 2)));
        m[individ.get_i()][individ.get_j()] = individ;
    }

    for (auto i : m) {
        print(i);
    }

    return 0;
}