#include <bits/stdc++.h>
using namespace std;

// Constants
#define INF 1001001001
#define PI 3.1415926535897932384626

// data types and stl
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

ofstream fout("pikachu.out", ios::out);
ifstream fin("pikachu.in", ios::in);

#define ui unsigned int
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a < b ? b : a)
#define REMAX(a, b) (a) = max((a), (b))  // set a to the maximum of a and b
#define REMIN(a, b) (a) = min((a), (b))

ui flatten(ui v[], ui h, ui k) {
    ui min = INF, ret = 0;
    ui n = sizeof(v) / sizeof(v[0]);
    for (int i = 0; i < n; i++) {
        // cout << "Itaration: " << i << '\n';
        // print(i);
        // print(ret);
        ret += abs<int>(v[i] - h);
        if (i >= k) {
            ret -= abs<int>(v[i - k] - h);
            REMIN(min, ret);
        }
    }
    return min;
}

int main() {
    ui max = 0, min = INF;
    ui n, k;
    fin >> n >> k;
    ui v[n];
    ui aux;
    for (int i = 0; i < n; i++) {
        fin >> aux;
        REMAX(max, aux);
        REMIN(min, aux);
        v[i] = aux;
    }

    ui s = min, d = max, m;
    ui sol;
    while (s <= d) {
        m = (s + d) / 2;
        // cout << "Left: " << s << "  Right: " << d << '\n';
        if (flatten(v, m - 1, k) > flatten(v, m + 1, k))
            s = m + 1;
        else
            d = m - 1;
    }
    fout << flatten(v, s, k);
    exit(0);
}

int getRandom(int min, int max) { return rand() % max + min; }
template <class T>
T get(string prompt) {
    cout << prompt;
    T ret;
    fin >> ret;
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
