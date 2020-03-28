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

template <class T>
class Matrice {
    vector<vector<T>> m;
    // constructor care poate genera o matrice cu numere random
   public:
    // Constructor de copiere
    Matrice(const Matrice &other) { m = other.m; }

    // sper ca nu e dubios, vreau un constructor, care sa-mi genereze o matrice
    // cu elemente random, alese dintr-o lista, fiecare element avand si o
    // probabilitate Am facut un pair, cu elemente, sa zicem Matice<char>(5,5,
    // {make_pair('a', 20), make_pair('b', 30)}, default = '0')
    //    ==> o matrice cu 25 de elemente dintre care aproximativ 20% adica 5 o
    //    sa fie 'a'-uri
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

            // sansa * cate spatii sunt pentru a obitne cate obiecte de tipul X
            // trebuie plasate in matrice
            float no_obj = chance / 100.0f * total_items;
            int placed = 0;

            // in caza ca mai sunt obiecte de pus pe matrice dar nu mai e loc
            // sau sunt prea putin locuri, cum i si j se aleg la intmplare
            // programul poate ramane foarte mult blocat pe taskul ast fool
            // proof adica, se aplica si in cazu in care sansa lui a este de
            // 100, si a lui b de 20, le ia in ordine
            int over_trying_counter = 0;
            while (placed < no_obj) {
                int i = getRandom(0, linii);
                int j = getRandom(0, coloane);

                if (over_trying_counter > 1000) break;

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

    // operatori
    friend ostream &operator<<(ostream &out, const Matrice &mat) {
        for (auto line : mat.m) {
            for (int i = 0; i < line.size(); i++) {
                if (i != line.size() - 1)
                    out << line[i] << " | ";
                else
                    out << line[i];
            }
            out << "\n";
        }
        return out;
    }

    vector<T> &operator[](int i) { return this->m[i]; }

    Matrice operator+(Matrice<T> other) {
        try {
            Matrice<T> ret = other;
            for (int i = 0; i < this->m.size(); i++) {
                for (int j = 0; j < this->m.size(); j++) {
                    ret[i][j] = m[i][j] + other[i][j];
                }
            }
            return ret;
        } catch (int e) {
            print(
                "Aparent asta nu merge dar daca se incearca adunarea a 2 "
                "matrice de dimenisuni diferite primesti un Segmentation "
                "fault");
        }
    }

    Matrice operator-(Matrice<T> other) {
        try {
            Matrice<T> ret = other;
            for (int i = 0; i < this->m.size(); i++) {
                for (int j = 0; j < this->m.size(); j++) {
                    ret[i][j] = m[i][j] - other[i][j];
                }
            }
            return ret;
        } catch (int e) {
            print("La fel ca sus.");
        }
    }

    Matrice operator*(Matrice<T> other) {
        // sanity check
        for (auto line : m) {
            if (m.size() != line.size()) {
                print("No good! 1");
                throw;
            }
        }
        for (auto line : other.m) {
            if (other.m.size() != line.size()) {
                // return -1;
                // raise exception
            }
        }
        if (m[0].size() != other.m.size()) {
            print("No good 2");
            throw invalid_argument("asdasd");
            // raise exception
        }

        Matrice<T> ret(m.size(), other.m[0].size(), 0);

        for (int i = 0; i < m.size(); i++) {
            for (int k = 0; k < other.m[0].size(); k++) {
                for (int j = 0; j < m[0].size(); j++) {
                    ret[i][j] = ret[i][j] + (m[i][j] * other.m[j][k]);
                }
            }
        }

        return ret;
    }

    int getNoInstanceOf(T instance) {
        int counter = 0;
        for (auto line : m) {
            for (auto element : line) {
                if (element == instance) counter++;
            }
        }
        return counter;
    }
};

int main() {
    srand(time(NULL));

    Complex c(2, 2);
    Complex c2(2, 2);
    print(c * c2);

    Matrice<int> m(5, 5, 10);
    print(m);
    Matrice<int> m2(2, 2, 2);
    print(m * m2);

    // // Declararea unei matrice
    // //@params: lini, cloane, initializare
    // Matrice<Complex> m(3, 3, Complex(2, 0));
    // // Printare
    // print("Matrice M:");
    // print(m);
    // Matrice<Complex> m2(3, 3, Complex(2, 0));
    // // atribuirea unui element
    // // Complex c(2, -6);
    // // m[0][0] = c;
    // // Adunare
    // // m = m - m2;
    // // print("Matricea m - m2:");
    // print(m2);
    // print(
    //     "Matricea m * m2 care nu cred ca merge bine din motive matematice
    //     :))");
    // // m = m * m2;
    // m = m * m2;
    // print(m);

    // Matrice<char> m2(
    //     10, 300, {make_pair('a', 15), make_pair('b', 25),
    //     make_pair('X', 50)}, '0');
    // print(m2);

    // for (auto a : {'a', 'b', 'X', '0'})
    //     print(m2.getNoInstanceOf(a));  // de cate ori apare
    //     fiecare element

    print("\n\n");
    return 0;
}