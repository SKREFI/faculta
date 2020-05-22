#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("proc2.in", ios::in);
    ofstream fout("proc2.out", ios::out);

    int n, m;
    fin >> n >> m;

    priority_queue<int, vector<int>, greater<int>> procesor;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> task;

    for (int i = 0; i < n; i++) procesor.push(i);

    int s, d;
    for (int i = 0; i < m; i++) {
        fin >> s >> d;
        while (!task.empty() && task.top().first <= s) {
            procesor.push(task.top().second);
            task.pop();
        }

        fout << procesor.top() + 1 << '\n';
        task.push(make_pair(s + d, procesor.top()));
        procesor.pop();
    }
    return 0;
}