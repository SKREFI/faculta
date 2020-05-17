// https://codeforces.com/problemset/problem/380/C
// sereja And Brackets

#include <bits/stdc++.h>
using namespace std;

int pairs(string s) {
    int stack = 0;
    int total = 0;
    for (auto e : s) {
        if (e == '(')
            stack += 1;
        else if (stack > 0) {
            stack--;
            total++;
        }
    }
    return total * 2;
}

int main() {
    string b;
    cin >> b;
    int n;
    cin >> n;
    while (n--) {
        int i, j;
        cin >> i >> j;
        i--;
        j--;
        cout << pairs(b.substr(i, j - i + 1)) << endl;
    }
}