#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("cautbin.in", ios::in);
    ofstream fout("cautbin.out", ios::out);

    int n;
    fin >> n;

    int temp;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        fin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    int m;
    fin >> m;
    for (int i = 0; i < m; i++) {
        int tip, x;
        fin >> tip >> x;

        switch (tip) {
            case 0:
                temp = upper_bound(v.begin(), v.end(), x) - v.begin();
                fout << ((temp < n && temp >= 1 && v[temp - 1] == x) ? temp
                                                                     : -1)
                     << endl;
                break;
            case 1:
                fout << lower_bound(v.begin(), v.end(), x + 1) - v.begin()
                     << endl;
                break;
            case 2:
                fout << upper_bound(v.begin(), v.end(), x - 1) - v.begin() + 1
                     << endl;
                break;
        }
    }
}
