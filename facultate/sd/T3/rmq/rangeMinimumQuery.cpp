#include <bits/stdc++.h>
using namespace std;

template <class T>
int min(vector<T> v, int i, int j) {
    int m = v[i];
    for (int k = i + 1; k <= j; k++) m = min(m, v[k]);
    return m;
}

template <class T>
T get(ifstream &ist, string prompt = "") {
    T ret;
    cout << prompt;
    ist >> ret;
    return ret;
}

int main() {
    ifstream fin = ifstream("rmq.in", ios::in);
    ofstream fout = ofstream("rmq.out", ios::out);
    int n, m;
    fin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; ++i) v.push_back(get<int>(fin));
    for (int i = 0; i < m; ++i) {
        int a, b;
        fin >> a >> b;
        fout << min<int>(v, a - 1, b - 1) << '\n';
    }
}