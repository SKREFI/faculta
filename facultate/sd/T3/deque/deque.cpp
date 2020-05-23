// https://www.infoarena.ro/problema/deque
// dequ O(n * k) => 20p ??? 
#include <bits/stdc++.h>
using namespace std;

ofstream fout("deque.out", ios::out);
ifstream fin("deque.in", ios::in);

int get() {
    int x;
    fin >> x;
    return x;
}

int main() {
    int n, k;
    fin >> n >> k;
    n -= k;

    deque<int> d;
    while (k--) d.push_back(get());

    int sum = *min_element(d.begin(), d.end());
    while (n--) {
        d.pop_front();
        d.push_back(get());
        sum += *min_element(d.begin(), d.end());
    }
    fout << sum;
}