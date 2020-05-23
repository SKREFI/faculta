// set > 60p

#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("hashuri.in", ios::in);
    ofstream fout("hashuri.out", ios::out);
    int n;
    fin >> n;
    set<int> s;
    int t, value;

    while (n--) {
        fin >> t;
        fin >> value;
        if (t == 1)
            s.insert(value);
        else if (t == 2)
            s.erase(value);
        else
            fout << (s.find(value) != s.end() ? 1 : 0) << endl;
    }
}