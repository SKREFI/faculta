// https://www.infoarena.ro/problema/radixsort
// 30p

#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1) os << ", ";
    }
    return os;
}

map<int, vector<int>> setup(int base) {
    map<int, vector<int>> d;
    for (int i = 0; i < base; ++i)
        d[i] = vector<int>();
    return d;
}

vector<int> mapToVector(map<int, vector<int>> d) {
    vector<int> v;
    for (map<int, vector<int>>::iterator it = d.begin(); it != d.end(); ++it)
        for (auto e : it->second) v.push_back(e);
    return v;
}

vector<int> radix(vector<int> inp, int base = 100) {
    if (inp.size() == 0) return inp;
    int digits = (int)(floor(log(*max_element(inp.begin(), inp.end())) / log(base))) + 1;
    int key = 1;
    for (int _ = 0; _ < digits; ++_) {
        map<int, vector<int>> d = setup(base);
        for (auto i : inp)
            d[((int)i / key) % base].push_back(i);
        inp = mapToVector(d);
        key *= base;
    }
    return inp;
}

int main() {
    ifstream fin("radixsort.in", ios::in);
    ofstream fout("radixsort.out", ios::out);

    int n, a, b, c;
    fin >> n >> a >> b >> c;
    vector<int> arr(n);
    arr[0] = b;
    for (int i = 1; i < n; ++i)
        arr[i] = (a * arr[i - 1] + b) % c;

    arr = radix(arr);

    for (int i = 0; i < arr.size(); i += 10) {
        fout << arr[i];
        if (i != arr.size() - 1) fout << " ";
    }
}