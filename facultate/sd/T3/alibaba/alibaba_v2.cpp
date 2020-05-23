// https://www.infoarena.ro/problema/paranteze

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
void print(T ret = "\n", string sep = "", string end = "\n");
template <typename T, typename S>
ostream &operator<<(ostream &out, const pair<T, S> &v);

ofstream fout("alibaba.out", ios::out);
ifstream fin("alibaba.in", ios::in);

int main() {
    stack<char> s;
    int n, k, i = 0;
    fin >> n >> k;
    while (i < n) {
        char d;
        fin >> d;
        while (k > 0 && !s.empty() && s.top() < d) {
            s.pop();
            k--;
        }
        s.push(d);
        i++;
    }
    while (k--) s.pop();

    string ret = "";
    while (!s.empty()) {
        ret += s.top();
        s.pop();
    }

    reverse(be(ret));
    fout << ret;

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
