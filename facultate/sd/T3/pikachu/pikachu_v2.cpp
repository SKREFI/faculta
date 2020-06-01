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

ofstream fout("pikachu.out", ios::out);
ifstream fin("pikachu.in", ios::in);

#define ui unsigned int
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a < b ? b : a)
#define REMAX(a, b) (a) = max((a), (b))  // set a to the maximum of a and b
#define REMIN(a, b) (a) = min((a), (b))

ui flatten(vi v, ui h, ui k) {
    ui ret = 0, min = INF;
    for (int i = 1; i < v.size(); i++) {
        ret += abs<int>(v[i] - h);
        if (i > k - 1) ret -= abs<int>(v[i - k + 1] - h);
        REMIN(min, ret);
    }
    return min;
}

int main() {
    ui max = 0;
    int min = -1;
    int n, k;
    fin >> n >> k;
    vi v;
    ui aux;
    for (int i = 0; i < n; i++) {
        fin >> aux;
        REMAX(max, aux);
        REMIN(min, aux);
        v.pb(aux);
    }

    print(v);
    print(min);
    print(max);

    ui s = min, d = max, m, ret;

    while (s <= d) {
        m = (s + d) / 2;
        print("Flatten comparation: ");
        print(flatten(v, m - 1, k) > flatten(v, m + 1, k));

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
