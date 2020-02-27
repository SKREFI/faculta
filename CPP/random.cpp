#include <bits/stdc++.h>
using namespace std;

vector<int> test() {
    vector<int> v;
    for (int i = 0; i < 5; i++) v.push_back(i);
    return v;
}

void foloseste(vector<int> v) {
    for (auto i : v) {
        cout << i << " ";
    }
}

int main() {
    foloseste(test());

    return 0;
}