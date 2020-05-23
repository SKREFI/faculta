// https://codeforces.com/problemset/problem/515/C
// 31ms

#include <bits/stdc++.h>
using namespace std;

//              2       3      4    5      6      7     8       9
bool prime[] = {true, true, false, true, false, true, false, false};

int main() {
    int dim;
    cin >> dim;
    dim++;

    vector<int> v(10);
    char *number = new char[dim];

    cin.get();
    cin.get(number, dim);

    for (int i = 0; i < dim - 1; i++) {
        int pos = int(number[i] - 48);
        if (pos == 1 || pos == 0) continue;

        bool is_prime = prime[pos - 2];

        for (int j = pos; j >= 2; j--) {
            if (!is_prime) {
                if (j == 9) {
                    v[3] += 2;
                    v[2] -= 2;
                }
                if (j == 8) v[2] += 3;
                if (j == 6) v[3]++;
                if (j == 4) v[2] += 2;
                is_prime = prime[j - 3];
            } else {
                v[j]++;
                break;
            }
        }
    }

    int counter = 0;
    number = new char[100];
    for (int i = 9; i >= 2; i--) {
        if (v[i] == 0)
            continue;

        while (v[i]--) number[counter++] = 48 + i;
    }

    number[counter] = '\0';
    cout << number;
    delete number;
}