// https://www.infoarena.ro/problema/radixsort
// 30p

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

int getMax(vector<int> arr) {
    return *max_element(arr.begin(), arr.end());
}

void countSort(vi &arr, int e) {
    int n = arr.size();
    vi output(n);
    vi count(10);

    for (int i = 0; i < n; i++)
        count[(arr[i] / e) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / e) % 10] - 1] = arr[i];
        count[(arr[i] / e) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radix(vi &arr) {
    for (int e = 1; getMax(arr) / e > 0; e *= 10)
        countSort(arr, e);
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

    radix(arr);

    for (int i = 0; i < arr.size(); i += 10) {
        fout << arr[i];
        if (i != arr.size() - 1) fout << " ";
    }

    return 0;
}