// https://www.infoarena.ro/problema/heapuri
// sets > 100p

#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("heapuri.in");
    ofstream fout("heapuri.out");
    int n, x;
    set<int> s;
    vector<int> v;
    fin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        fin >> t;
        switch (t) {
            case 1:
                fin >> x;
                s.insert(x);
                v.push_back(x);
                break;
            case 2:
                fin >> x;
                s.erase(v[x - 1]);
                break;
            default:
                fout << *s.begin() << '\n';
                break;
        }
    }
}