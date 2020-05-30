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
void print(T ret = "\n", string end = "\n");
template <typename T, typename S>
ostream &operator<<(ostream &out, const pair<T, S> &v);

ofstream fout("arbint.out", ios::out);
ifstream fin("arbint.in", ios::in);

class SegmentTree {
   public:
    vi tree;
    vi v;

   public:
    SegmentTree(vi v, int n) : v(v) {
        for (int i = 0; i < 4 * n + 1; i++) tree.pb(-1);
    };

    int build(int node, int s, int d) {
        if (s > d) tree[node] = -1;
        if (s == d)
            tree[node] = v[s];
        else if (s < d)
            tree[node] = max(
                this->build(node * 2, s, (s + d) / 2),
                this->build(node * 2 + 1, (s + d) / 2 + 1, d));
        return tree[node];
    }

    int getMax(int node, int ns, int nd, int s, int d) {
        if (ns > nd || d < ns || nd < s)
            return -1;
        else if (s <= ns && nd <= d)
            return tree[node];
        else
            return max(
                getMax(node * 2, ns, (ns + nd) / 2, s, d),
                getMax(node * 2 + 1, (ns + nd) / 2 + 1, nd, s, d));
    }

    void update(int node, int ns, int nd, int i, int x) {
        if (ns > nd || i < ns || nd < i)
            return;
        else if (ns == x && ns == nd)
            tree[node] = x;
        else {
            update(node * 2, ns, (ns + nd) / 2, i, x);
            update(node * 2 + 1, (ns + nd) / 2 + 1, nd, i, x);

            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        }
    }
};

int main() {
    int n, m;
    fin >> n >> m;
    vi v;
    int nn = n;
    getVector(v, n);
    n = nn;
    SegmentTree tree(v, n);

    print(tree.tree);
    print(tree.v);

    int t, a, b;
    while (m--) {
        fin >> t >> a >> b;
        a--;
        b--;

        if (t)
            tree.update(1, 0, n - 1, a, b + 1);
        else
            fout << tree.getMax(1, 0, n - 1, a, b);
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
