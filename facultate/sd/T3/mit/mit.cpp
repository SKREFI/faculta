// Basic method. 40 de puncte.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("mit.in", ios::in);
    ofstream fout("mit.out", ios::out);

    int n, t;
    fin >> n >> t;
    int v[n];
    for (int i = 0; i < n; i++) {
        int x;
        fin >> x;
        v[i] = x;
    }

    while (t--) {
        int tip;
        fin >> tip;
        if (tip == 1) {
            int a, b;
            fin >> a >> b;
            a--;
            b--;
            fout << *max_element(v + a, v + b + 1) << endl;
        } else {
            int a, b, x;
            fin >> a >> b >> x;
            a--;
            b--;
            for (int i = a; i <= b; i++) v[i] += x;
        }
    }
}