#include <bits/stdc++.h>
using namespace std;

// Constants
#define INF 1001001001
#define PI 3.1415926535897932384626

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
    while (n--) v.pb(get<int>());
#define isInside binary_search
#define be(v) v.begin(), v.end()
// Things

int getRandom(int min, int max);
template <class T>
T get(string prompt = "");
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v);
template <class T>
void print(T ret = "\n", string end = "\n");
template <typename T, typename S>
ostream &operator<<(ostream &out, const pair<T, S> &v);

ofstream fout("order.out", ios::out);
int main() {
    ifstream fin("order.in", ios::in);

    int n;
    fin >> n;
    //        index visitat
    vector<pair<int, bool>> v;
    int n_back = n;
    int i = 0;
    while (n--) v.push_back(make_pair(i++, 0));
    n = n_back;

    int pozitie = 0;
    for (int i = 1; i <= n; i++) {
        int i2 = i;
        while (i2) {
            pozitie++;
            if (pozitie >= v.size()) pozitie = 0;
            if (v[pozitie].second != 1)  // daca este deja vizitat continuam adica nu micsoram i2
                i2--;
        }
        v[pozitie].second = 1;  // visitat
        fout << pozitie + 1 << ' ';
    }

    exit(0);
}

int getRandom(int min, int max) { return rand() % max + min; }
template <class T>
T get(string prompt) {
    cout << prompt;
    T ret;
    cin >> ret;
    return ret;
}

// Operator overloading for vectors
template <typename T>
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

// Pythonic type print function
template <class T>
void print(T ret, string end) {
    cout << ret << end;
}
// Pair << overloader
template <typename T, typename S>
ostream &operator<<(ostream &out, const pair<T, S> &v) {
    out << "(";
    out << v.first << ", " << v.second << ")";
    return out;
}
