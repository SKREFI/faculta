#include <bits/stdc++.h>
using namespace std;

// constants
#define INF 1001001001
#define PI 3.1415926535897932384626

// data types annd stl
typedef long long ll;
#define ull unsigned ll
typedef vector<int> vi;
#define pb push_back
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef map<int, int> d;
typedef map<int, vi> dvi;

// Functiond
#define getVector(v, n) \
    while (n--) v.pb(get<int>());
#define isIndide binary_search
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

ofstream fout("arbint.out", ios::out);
ifstream fin("arbint.in", ios::in);

vi tree;

int build(vi v, int node, int s, int d) {
    if (s > d) tree[node] = -1;
    if (s == d)
        tree[node] = v[s];
    else
        tree[node] = max(build(tree, node * 2, s, (s + d) / 2), build(tree, node * 2 + 1, (s + d) / 2 + 1, d));
    return tree[node];
}

//         tree    nod   nod stanga/ nod dreapta.. s/d
int getMax(int node, int ns, int nd, int s, int d) {
    if (ns > nd or d < ns or nd < s)
        return -1;  // invalid
    else if (s <= ns && nd <= d)
        return tree[node];  // suntem in interval
    else
        return max(
            getMax(node * 2, ns, (ns + nd) / 2, s, d),         // maxim dintre sub treeul stang
            getMax(node * 2 + 1, (ns + nd) / 2 + 1, nd, s, d)  // si sub treeul drept
        );
}

void update(int node, int ns, int nd, int i, int x) {
    if (ns > nd or x < ns or nd < x)
        return;  // sanity check
    else if (ns == x && ns == nd)
        tree[i] = x;
    else {
        update(node * 2, ns, (ns + nd) / 2, i, x);
        update(node * 2 + 1, (ns + nd) / 2 + 1, nd, i, x);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
}

int main() {
    int n, m, nn;
    fin >> n >> m;
    nn = n;
    vi v;
    getVector(v, n);
    n = nn;

    for (int i = 0; i < 4 * n + 1; i++) tree.pb(-1);

    build(tree, 0, 0, n - 1);

    int t, a, b;
    while (m--) {
        fin >> t >> a >> b;
        a--;
        b--;
        if (t)
            update(1, 0, n - 1, a, b + 1);  // b + 1 datorite inclusivitatii
        else
            fout << getMax(1, 0, n - 1, a, b) << '\n';
    }

    exit(0);
}

int getRandom(int min, int max) { return rand() % max + min; }
template <class T>
T get(string prompt) {
    // cout << prompt;
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
    for (unsigned int i = 0; i < v.size(); ++i) {
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
