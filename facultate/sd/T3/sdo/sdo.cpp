// https://www.infoarena.ro/problema/sdo
// nth_element -> 100p

#define vi vector<int>

#include <bits/stdc++.h>
using namespace std;

ifstream fin("sdo.in", ios::in);

int get() {
    int x;
    fin >> x;
    return x;
}

int main() {
    ofstream fout("sdo.out", ios::out);
    int n, k;
    fin >> n >> k;
    vi v;
    for (auto e : v) {
        cout << e << endl;
    }

    while (n--) v.push_back(get());
    nth_element(v.begin(), v.begin() + k - 1, v.begin() + v.size());

    fout << v[k - 1];
}