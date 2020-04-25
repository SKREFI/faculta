#include <bits/stdc++.h>
using namespace std;

int getRandom(int min, int max);
vector<int> range(int stop);
vector<int> range(int start, int stop);
vector<int> range(int start, int stop, int step);
template <class T>
T get(string prompt);
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v);
template <class T>
void print(T ret = "\n", string sep = "", string end = "\n");
template <typename T, typename S>
ostream &operator<<(ostream &out, const pair<T, S> &v);
void my_exit();

int main() {
    // ==============
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a, b;
        bool serii = 0;
        int counter = 1;
        cin >> a;
        for (int i = 0; i < n; i++) {
            cin >> b;
            if (a + 1 == b) {
                counter += 1;
                b = a;
            } else if (counter == 1) {
                a = b;
            } else if (counter > 1) {
                serii++;
                counter = 1;
            }
        }
        cout << serii << endl;
    }
    // ==============
    // my_exit();
    return 0;
}

int getRandom(int min, int max) { return rand() % max + min; }
vector<int> range(int stop) {
    vector<int> ret;
    for (int i = 0; i < stop; i++) {
        ret.push_back(i);
    }
    return ret;
}
vector<int> range(int start, int stop) {
    vector<int> ret;
    for (int i = start; i < stop; i++) {
        ret.push_back(i);
    }
    return ret;
}
vector<int> range(int start, int stop, int step) {
    vector<int> ret;
    for (int i = start; i < stop; i += step) {
        ret.push_back(i);
    }
    return ret;
}
template <class T>
T get(string prompt) {
    cout << prompt;
    T ret;
    cin >> ret;
    return ret;
}
// Operator overloading pentru vectori, print vector adica :))
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
template <class T>
void print(T ret, string sep, string end) {
    cout << ret << sep << end;
}
template <typename T, typename S>
ostream &operator<<(ostream &out, const pair<T, S> &v) {
    out << "(";
    out << v.first << ", " << v.second << ")";
    return out;
}
void my_exit() {
    print("\n\n__-==DONE==-__");

    exit(1);
}
