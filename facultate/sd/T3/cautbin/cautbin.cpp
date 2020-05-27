// Cautare binara cu stl upper/lower_bound > 60p

#include <bits/stdc++.h>
using namespace std;

// data types and stl
typedef long long ll;
#define ull unsigned ll
typedef vector<int> vi;
#define pb push_back
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef map<int, int> d;
typedef map<int, vi> dvi;

// Functions
#define getVector(v, n) \
    while (n--) v.pb(get<int>(fin));
#define isInside binary_search
#define be(v) v.begin(), v.end()
// Things
template <class T>
T get(ifstream &fin) {
    T ret;
    fin >> ret;
    return ret;
}

int main() {
    ifstream fin("cautbin.in", ios::in);
    ofstream fout("cautbin.out", ios::out);

    int n = get<int>(fin);

    vector<int> v;
    for (int i = 1; i <= n; i++) v.push_back(get<int>(fin));

    sort(v.begin(), v.end());
    int temp;
    int m = get<int>(fin);
    for (int i = 0; i < m; i++) {
        int tip = get<int>(fin), x = get<int>(fin);

        switch (tip) {
            case 0:
                temp = upper_bound(v.begin(), v.end(), x) - v.begin();
                fout << ((temp < n && temp >= 1 && v[temp - 1] == x) ? temp : -1)
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
