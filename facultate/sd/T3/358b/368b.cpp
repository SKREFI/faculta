// https://codeforces.com/problemset/problem/368/B

#include <bits/stdc++.h>
using namespace std;

// Constants
#define INF 1001001001
#define PI 3.1415926535897932384626

// data types and stl
typedef pair<int, int> ii;
#define mp make_pair
typedef long long ll;
#define ull unsigned ll
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
#define pb push_back
typedef set<int> s;
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
void print(T ret = "\n", string sep = "", string end = "\n");
template <typename T, typename S>
ostream &operator<<(ostream &out, const pair<T, S> &v);

int main() {
    int n = get<int>(), m = get<int>();
    vii v;
    s s;
    while (n--) {
        int inp = get<int>();
        v.pb(mp(inp, 0));
    }

    for (int i = v.size(); i >= 0; i--) {
        s.insert(v[i].first);
        v[i].second = s.size() - 1;
    }

    int l;
    while (m--) {
        l = get<int>();
        l--;
        print(v[l].second);
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
void print(T ret, string sep, string end) {
    cout << ret << sep << end;
}
// Pair << overloader
template <typename T, typename S>
ostream &operator<<(ostream &out, const pair<T, S> &v) {
    out << "(";
    out << v.first << ", " << v.second << ")";
    return out;
}
