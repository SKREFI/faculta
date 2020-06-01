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

ui rot(float x) {
    return x - (int)x > .50 ? (int)x + 1 : (int)x;
}

float sum(deque<int> d) {
    ui sum = 0;
    for (auto e : d) {
        sum += e;
    }
    return sum;
}

ui getTime(deque<int> d, ui k) {
    ui medie = rot(sum(d) / k);
    ui total = 0;
    for (auto e : d) {
        total += abs<int>(e - medie);
    }

    print("Deque:");
    for (auto e : d) {
        print(e);
    }

    print("Medie:");
    print(medie);

    return total;
}

int main() {
    ui n, k;
    fin >> n >> k;
    vi v;
    getVector(v, n);

    deque<int> d;
    ui i = 0;
    for (i = 0; i < k; i++) {
        d.push_back(v[i]);
    }

    vi solution;
    n = v.size();
    while (i <= n) {
        solution.pb(getTime(d, k));
        d.pop_front();
        d.push_back(v[i]);
        i++;
    }

    print("vector");
    print(solution);
    fout << *min_element(be(solution));

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
