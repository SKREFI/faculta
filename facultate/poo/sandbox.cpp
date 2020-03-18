#include <bits/stdc++.h>
using namespace std;

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
    for (int i = start; i < stop; i + step) {
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
    os << "Vector[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1) os << ", ";
    }
    os << "]";
    return os;
}
// overlaoding pentru Pair
template <typename T, typename S>
ostream &operator<<(ostream &out, const pair<T, S> &v) {
    out << "(";
    out << v.first << ", " << v.second << ")";
    return out;
}

template <class T>
void print(T x, string sep = " ", string end = "\n") {
    cout << x << sep << end;
}

class Complex {
    double r, i;

   public:
    // constructor
    Complex(double r = 0, double i = 0) {
        this->r = r;
        this->i = i;
    }
    // methods
    double modul() { return sqrt((r * r + i * i)); }
    // operator overloading
    Complex operator+(Complex c) {
        Complex res;
        res.setR(r + c.getR());
        res.setI(i + c.getI());
        return res;
    }
    Complex operator+=(Complex c) {
        return Complex(this->r + c.getR(), this->i + c.getI());
    }
    Complex operator*(double x) { return Complex(r * x, i * x); }
    Complex operator-(Complex c) {
        Complex res;
        res.setR(r - c.getR());
        res.setI(i - c.getI());
        return res;
    }
    Complex operator*(Complex c) {
        Complex res;
        res.setR(r * c.getR() - i * c.getI());
        res.setI(r * c.getI() + c.getR() * i);
        return res;
    }
    Complex operator/(Complex comp) {
        Complex res;
        double a = r, b = i, c = comp.getR(), d = comp.getI();
        res.setR((a * c + b * d) / (c * c + d * d));
        res.setI((b * c - a * d) / (c * c + d * d));
        return res;
    }
    friend ostream &operator<<(ostream &out, const Complex &c) {
        if (c.i == 0)
            out << c.r;
        else if (c.i == 1)
            out << c.r << " + i";
        else if (c.i == -1)
            out << c.r << " - i";
        else if (c.i < 0)
            out << c.r << " - i" << -c.i;
        else if (c.i > 0)
            out << c.r << " + i" << c.i;
        else
            out << "CASE NOT TREATED IN CLASS COMPLEX";
        return out;
    }
    // geters/seters
    double getR() { return this->r; }
    double getI() { return this->i; }
    void setR(double r) { this->r = r; }
    void setI(double i) { this->i = i; }
};

class Polinom {
    int grad;
    vector<int> coeficienti;
    string litere = "abcdefghijkl";
    // string litere = {'a', 'b', 'c', 'd', 'e', 'f',
    //                  'g', 'h', 'i', 'j', 'k', 'l'};

   public:
    // constructori
    Polinom() {  // polinom null
        vector<int> v;
        this->coeficienti = v;
        grad = v.size() - 1;
    }
    Polinom(vector<int> co) {
        this->coeficienti = co;
        this->grad = co.size() - 1;
    }
    // methods
    pair<Complex, Complex> solve() {  // works only for grad == 2
        if (grad != 2) {
            print("Polinomul nu este de grad 2!");

            return make_pair(NULL,
                             NULL);  // TOASK: Cum fac asta sa functioneza?
                                     // (prima data era return;)
        }
        double a = coeficienti[0];
        double b = coeficienti[1];
        double c = coeficienti[2];
        double delta = (b * b) - (4 * a * c);
        if (delta > 0) {
            return make_pair(Complex(-b / 2 * a + sqrt(delta) / 2 * a, 0),
                             Complex(-b / 2 * a - sqrt(delta) / 2 * a, 0));
        } else {
            return make_pair(Complex(-b / 2 * a, sqrt(-delta) / 2 * a),
                             Complex(-b / 2 * a, -sqrt(-delta) / 2 * a));
        }
    }
    // oprator overloading
    friend ostream &operator<<(ostream &out, Polinom p) {
        int n = p.getCo().size();
        int c = p.getCo()[0];
        char l = 'X';
        if (c == 1) {
            out << l << "^" << n - 1;
        } else {
            out << c << l << "^" << n - 1;
        }
        int lc = c;
        char ll = l;
        for (auto i : range(1, n)) {
            c = p.getCo()[i];
            if (c == 0) {
                continue;
            }
            if (c == 1 && i == n - 1) {
                out << " + " << c;
            } else if (c == 1) {
                out << l << "^" << n - 1 - i;
            } else {
                if (c < 0) {
                    if (n - 1 - i == 1) {
                        out << " - " << -c << l;
                    } else if (n - 1 - i == 0) {
                        out << " - " << -c;
                    } else {
                        out << " - " << -c << l << "^" << n - 1 - i;
                    }
                } else {
                    if (n - 1 - i == 1) {
                        out << " + " << c << l;
                    } else if (n - 1 - i == 0) {
                        out << " + " << c;
                    } else {
                        out << " + " << c << l << "^" << n - 1 - i;
                    }
                }
            }
        }
        // TOASK: De ce nu pot sa iau direct litera
        // print(this->litere[0]);
        return out;
    }
    // geters/seters
    vector<int> getCo() { return this->coeficienti; };
    char getLitera(int i) { return this->litere[i]; }
};

template <class T>
class Matrice {
    vector<vector<T>> m;
    // constructor care poate genera o matrice cu numere random
   public:
    // sper ca nu e dubios, vreau un constructor, care sa-mi genereze o matrice
    // cu elemente random, alese dintr-o lista, fiecare element avand si o probabilitate
    // Am facut un pair, cu elemente, sa zicem
    // Matice<char>(5,5, {make_pair('a', 20), make_pair('b', 30)}, default = '0')
    //    ==> o matrice cu 25 de elemente dintre care aproximativ 20% adica 5 o sa fie 'a'-uri
    // Fac asta mai mult pentru D10, (matrice de 'indivizi')
    Matrice(int linii, int coloane, vector<pair<T, float>> choices, T def) {
        vector<vector<T>> ret;
        for (auto _ : range(linii)) {
            vector<T> linie;
            for (auto __ : range(coloane)) {
                linie.push_back(def);
            }
            ret.push_back(linie);
        }
        int total_items = linii * coloane;
        for (auto p : choices) {
            T item = p.first;
            int chance = p.second;

            //sansa * cate spatii sunt pentru a obitne cate obiecte de tipul X trebuie plasate in matrice
            float no_obj = chance / 100.0f * total_items;
            int placed = 0;

            // in caza ca mai sunt obiecte de pus pe matrice dar nu mai e loc sau sunt prea putin locuri, cum i si j se aleg la
            // intmplare programul poate ramane foarte mult blocat pe taskul ast
            // fool proof adica, se aplica si in cazu in care sansa lui a este de 100, si a lui b de 20, le ia in ordine
            int over_trying_counter = 0;
            while (placed < no_obj) {
                int i = getRandom(0, linii);
                int j = getRandom(0, coloane);

                if (over_trying_counter > 1000)
                    break;

                if (ret[i][j] == def) {
                    placed++;
                    ret[i][j] = item;
                    over_trying_counter = 0;
                }
                over_trying_counter++;
            }
        }

        m = ret;
    }

    Matrice(int linii, int coloane, bool randomInt = true, int min = 0,
            int max = 0) {
        vector<vector<int>> ret;
        for (auto _ : range(linii)) {
            vector<int> linie;
            for (auto __ : range(coloane)) {
                if (randomInt)
                    linie.push_back(getRandom(min, max + 1));
                else
                    linie.push_back(0);
            }
            ret.push_back(linie);
        }
        m = ret;
    }
    // Constructor care initializeaza matricea cu on anumit obiect
    Matrice(int linii, int coloane, T init) {
        vector<vector<T>> ret;
        for (auto _ : range(linii)) {
            vector<T> linie;
            for (auto __ : range(coloane)) {
                linie.push_back(init);
            }
            ret.push_back(linie);
        }
        m = ret;
    }

    friend ostream &operator<<(ostream &out, const Matrice &mat) {
        for (auto line : mat.m) {
            for (auto e : line) {
                out << e << " ";
            }
            out << "\n";
        }
        return out;
    }

    int getNoInstanceOf(T instance) {
        int counter = 0;
        for (auto line : m) {
            for (auto element : line) {
                if (element == instance)
                    counter++;
            }
        }
        return counter;
    }
};

int main() {
    srand(time(NULL));

    Complex c(2, 3);
    Complex c2(5, 6);
    // cout << "Impartire: " << c / c2 << '\n';
    // cout << "Adunare: " << c + c2 << '\n';
    // cout << "Modul: " << c.modul() << '\n';  // sqrt(13)
    Polinom p({1, -2, 2});  // solutii imaginare
    print(p);
    print(p.solve());
    print(Polinom({1, -2, 1}).solve());  // o singur solutie reala

    Matrice<int> m(5, 5, true, 0, 9);
    // print(m);

    Matrice<char> m2(10, 300, {make_pair('a', 15), make_pair('b', 25), make_pair('X', 50)}, '0');
    print(m2);

    for (auto a : {'a', 'b', 'X', '0'})
        print(m2.getNoInstanceOf(a)); // de cate ori apare fiecare element

    print("\n\n");
    return 0;
}



/*
backup:

#include <bits/stdc++.h>
using namespace std;

template <class T>
void print(T x, string sep = " ", string end = "\n") {
    cout << x << sep << end;
}

void exit() { print("\n\nDONE"); }

struct Node {
   private:
    int data;
    struct Node* next;

   public:
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    int getData() { return this->data; }
    void setNext(Node* n) { this->next = n; }
    Node* getNext() { return this->next; }
};

int main() {
    Node head(1);
    print(head.getData());
    Node second(2);
    head.setNext(&second);
    print(head.getNext().getData());

    exit();
}

*/