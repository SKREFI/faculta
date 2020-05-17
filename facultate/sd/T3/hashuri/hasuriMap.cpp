// map sau unordered_map > 0 puncte

#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("hashuri.in", ios::in);
    ofstream fout("hashuri.out", ios::out);
    map<int, int> m;
    int n;
    fin >> n;
    int tip, value;

    while (n--) {
        fin >> tip >> value;
        if (tip == 1) m[value] = 1;
        if (tip == 2) m.erase(value);
        if (tip == 3) fout << (m.find(value) != m.end());
    }
}