/* Sandu Razvan Alexandru 134
g++ c++14                       (gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0)
David Păcioianu */

#include <bits/stdc++.h>
using namespace std;

// Functi si macrouri
typedef vector<int> vi;
#define ll long long

template <class T>  // print in stil python
void print(T object, string end = "\n") { cout << object << end; }

template <class T>  // Prototipul functiei de get pentru citirea de la tastatura
T get(const string prompt = "");

// Operator overloading for vectors
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    // Afisam elementele din vector
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        // un simpu test ca sa nu afiseze virgula la sfarsitul vectorului
        if (i != v.size() - 1) os << ", ";
    }
    return os;
}

class MascaChirurgicala {
   protected:
    string culoare;
    int ffp;
    int nr_pliuri;

    // functie virtuala pentru output stream
    virtual void format(ostream &os) const;

   public:
    int getFfp() { return this->ffp; }

    // constructor(i)
    MascaChirurgicala(){};
    MascaChirurgicala(string culoare, int ffp, int nr_pliuri);

    // prototipuri functii friend de citire/afisare
    friend istream &operator>>(istream &is, MascaChirurgicala &obj);
    friend ostream &operator<<(ostream &os, const MascaChirurgicala &obj);
};

MascaChirurgicala::MascaChirurgicala(string culoare, int ffp, int nr_pliuri) : culoare(culoare), ffp(ffp), nr_pliuri(nr_pliuri){};

// Definirea supraincarcarii operatorului >> pentru afisarea citirea datelor clasei MascaChirurgicala
istream &operator>>(istream &is, MascaChirurgicala &obj) {
    print("Culoare masca: ", "");
    is >> obj.culoare;
    print("Protectie masca: ", "");
    is >> obj.ffp;
    print("Nr. pliuri masca: ", "");
    is >> obj.nr_pliuri;
    return is;
}

// functie separata helper pentru supraincaracarea opeartorului << pentru a permite virtualizarea supraincarcarii
void MascaChirurgicala::format(ostream &os) const {
    os << "Culoare: " << culoare << '\n';
    os << "Protectie: " << ffp << '\n';
    os << "Nr. pliuri: " << nr_pliuri << '\n';
}
// Definirea supraincarcarii operatorului << pentru afisarea datelor clasei MascaChirurgicala
ostream &operator<<(ostream &os, const MascaChirurgicala &obj) {
    obj.format(os);
    return os;
}

class MascaPolicarbonat : public MascaChirurgicala {
   private:
    const int ffp = 0;
    string tip_prindere;

   private:
    // functie virtuala pentru output stream
    void format(ostream &os) const;

   public:
    MascaPolicarbonat(){};
    MascaPolicarbonat(string culoare, int nr_pliuri, string tip_prindere);

    // prototipuri functii friend de citire/afisare
    friend istream &operator>>(istream &is, MascaPolicarbonat &obj);
    friend ostream &operator<<(ostream &os, const MascaPolicarbonat &obj);
};

MascaPolicarbonat::MascaPolicarbonat(string culoare, int nr_pliuri, string tip_prindere) : MascaChirurgicala(culoare, 0, nr_pliuri), tip_prindere(tip_prindere){};

// Definirea supraincarcarii operatorului >> pentru afisarea citirea datelor clasei MascaPolicarbonat::MascaPolicarbonat(string culoare, int ffp, int nr_pliuri, string tip_prindere) : MascaChirurgicala(culoare, ffp, nr_pliuri), tip_prindere(tip_prindere){};

istream &operator>>(istream &is, MascaPolicarbonat &obj) {
    print("Culoare masca: ", "");
    is >> obj.culoare;
    print("Nr. pliuri masca: ", "");
    is >> obj.nr_pliuri;
    print("Tip prindere: ", "");
    is >> obj.tip_prindere;
    return is;
}

ostream &operator<<(ostream &os, const MascaPolicarbonat &obj) {
    obj.format(os);
    return os;
}

// functie separata helper pentru supraincaracarea opeartorului << pentru a permite virtualizarea supraincarcarii
void MascaPolicarbonat::format(ostream &os) const {
    os << "Culoare: " << culoare << '\n';
    os << "Protectie: " << ffp << '\n';
    os << "Nr. pliuri: " << nr_pliuri << '\n';
    os << "Tip prindere: " << tip_prindere << '\n';
}

class Dezinfectant {
   protected:
    // ll = long long, defineul este sus de tot
    // constante pentru numarul total de.. virusi
    const ll nr_total = 0;
    // functie virtuala pentru output stream
    virtual void format(ostream &os) const;

    ll numar_specii;
    vector<string> ingrediente;
    vector<string> suprafete;

   public:
    // interfata pentru getEficienta
    virtual float getEficienta() {}

    Dezinfectant(){};
    Dezinfectant(ll numar_specii, vector<string> ingrediente, vector<string> suprafete);

    // prototipuri functii friend de citire/afisare
    // de implementat citirea daca mai am timp, constructorul este suficient pentru moment
    // friend istream &operator>>(istream &is, Dezinfectant &obj);
    friend ostream &operator<<(ostream &os, const Dezinfectant &obj);
};

Dezinfectant::Dezinfectant(ll numar_specii, vector<string> ingrediente, vector<string> suprafete) : ingrediente(ingrediente), suprafete(suprafete){};

// functie separata helper pentru supraincaracarea opeartorului << pentru a permite virtualizarea supraincarcarii
void Dezinfectant::format(ostream &os) const {
    // Supra incarcarea operatorului << pentru vectori este sus
    os << "Ingrediente: " << ingrediente << '\n';
    os << "Suprafete: " << suprafete << '\n';
    os << "Numar specii: " << numar_specii << '\n';
}
ostream &operator<<(ostream &os, const Dezinfectant &obj) {
    obj.format(os);
    return os;
}

// istream &operator>>(istream &is, MascaPolicarbonat &obj) {
// }

class DezifectantBacterii : virtual public Dezinfectant {
   protected:
    const ll nr_total = pow(10, 9);

   protected:
    // functie virtuala pentru output stream
    virtual void format(ostream &os) const;
    float eficienta;

    virtual float getEficienta() { return eficienta; }

   public:
    DezifectantBacterii(){};  // necesar pentru accesarea nr_total in constructorul DezinfectantUniversal
    DezifectantBacterii(ll numar_specii, vector<string> ingrediente, vector<string> suprafete);

    friend ostream &operator<<(ostream &os, const DezifectantBacterii &obj);
};

DezifectantBacterii::DezifectantBacterii(ll numar_specii, vector<string> ingrediente, vector<string> suprafete)
    : Dezinfectant(numar_specii, ingrediente, suprafete), eficienta(numar_specii / nr_total){};

ostream &operator<<(ostream &os, const DezifectantBacterii &obj) {
    obj.format(os);
    return os;
}

// supraincarcarea virtuala pentru ouput stream
void DezifectantBacterii::format(ostream &os) const {
    // apelarea formatului din clasa de baza pentru campurile comune
    Dezinfectant::format(os);
    os << "Numar specii: " << numar_specii;
    os << "Eficienta: " << eficienta;
}

class DezifectantFungi : virtual public Dezinfectant {
   protected:
    const ll nr_total = 1.5 * pow(10, 6);

    // functie virtuala pentru output stream
    virtual void format(ostream &os) const;

   protected:
    float eficienta;

    virtual float getEficienta() { return eficienta; }

   public:
    DezifectantFungi(){};
    DezifectantFungi(ll numar_specii, vector<string> ingrediente, vector<string> suprafete);

    friend ostream &operator<<(ostream &os, const DezifectantFungi &obj);
};

// supraincarcarea virtuala pentru ouput stream
void DezifectantFungi::format(ostream &os) const {
    // apelarea formatului din clasa de baza pentru campurile comune
    DezifectantFungi::format(os);
    os << "Numar specii: " << numar_specii;
    os << "Eficienta: " << eficienta;
}

ostream &operator<<(ostream &os, const DezifectantFungi &obj) {
    obj.format(os);
    return os;
}

DezifectantFungi::DezifectantFungi(ll numar_specii, vector<string> ingrediente, vector<string> suprafete)
    : Dezinfectant(numar_specii, ingrediente, suprafete), eficienta(numar_specii / nr_total){};

class DezifectantVirusi : virtual public Dezinfectant {
   protected:
    const ll nr_total = pow(10, 8);

    // functie virtuala pentru output stream
    virtual void format(ostream &os) const;

   protected:
    float eficienta;

    virtual float getEficienta() { return eficienta; }

   public:
    DezifectantVirusi(){};
    DezifectantVirusi(ll numar_specii, vector<string> ingrediente, vector<string> suprafete);

    friend ostream &operator<<(ostream &os, const DezifectantVirusi &obj);
};

// supraincarcarea virtuala pentru ouput stream
void DezifectantVirusi::format(ostream &os) const {
    // apelarea formatului din clasa de baza pentru campurile comune
    DezifectantVirusi::format(os);
    os << "Numar specii: " << numar_specii;
    os << "Eficienta: " << eficienta;
}

DezifectantVirusi::DezifectantVirusi(ll numar_specii, vector<string> ingrediente, vector<string> suprafete)
    : Dezinfectant(numar_specii, ingrediente, suprafete), eficienta(numar_specii / nr_total){};

ostream &operator<<(ostream &os, const DezifectantVirusi &obj) {
    obj.format(os);
    return os;
}

// Disclaimer, nu prea stiu ce se intampla cu clasa asta
// Enuntul precizeaza: bineinteles ca se producatorul va produce si dezinfectant universal
// mai mult de atat nu spune deci nu prea stiu ce ar trebui sa faca
class DezinfectantUniversal : virtual public DezifectantVirusi, virtual public DezifectantBacterii, virtual public DezifectantFungi {
    // private intrucat nu mai nu mai este parintele nimanui
   private:
    float eficienta_bacterii;
    float eficienta_fungi;
    float eficienta_virusi;
    void format(ostream &os) const;

    virtual float getEficienta(){};

   public:
    DezinfectantUniversal(ll numar_specii_bacterii,
                          ll numar_specii_fungi,
                          ll numar_specii_virusi,
                          vector<string> ingrediente, vector<string> suprafete);

    friend ostream &operator<<(ostream &os, const DezinfectantUniversal &obj);
};

// Definitie Constructor Dezifectant Universal
DezinfectantUniversal::DezinfectantUniversal(ll numar_specii_bacterii,
                                             ll numar_specii_fungi,
                                             ll numar_specii_virusi,
                                             vector<string> ingrediente, vector<string> suprafete)
    : Dezinfectant(numar_specii, ingrediente, suprafete),
      eficienta_bacterii(numar_specii_bacterii / DezifectantBacterii::nr_total),
      eficienta_fungi(numar_specii_fungi / DezifectantFungi::nr_total),
      eficienta_virusi(numar_specii_virusi / DezifectantVirusi::nr_total){};

void DezinfectantUniversal::format(ostream &os) const {
    Dezinfectant::format(os);
    os << "Eficienta specii bacterii" << eficienta_bacterii << '\n';
    os << "eficienta_bacterii specii fungi" << eficienta_bacterii << '\n';
    os << "eficienta_bacterii specii virusi" << eficienta_bacterii << '\n';
}

ostream &operator<<(ostream &os, const DezinfectantUniversal &obj) {
    obj.format(os);
    return os;
}

// mostenim cele 2 pentru a avea acces la ffp
class Achizitie : public MascaChirurgicala, public Dezinfectant {
   private:
    string nume_client;
    vector<MascaChirurgicala *> masti;
    vector<Dezinfectant *> dezinfectanti;
    int total_comenzii;  // aceast imi asum ca este pretul

    // functie virtuala pentru output stream
    void format(ostream &os) const;

   public:
    Achizitie(string nume_client) : nume_client(nume_client){};

    void adaugaMasca(MascaChirurgicala *masca);
    void adaugaDezifectant(Dezinfectant *dezinfectant);

    friend ostream &operator<<(ostream &os, const Achizitie &obj);
};

void Achizitie::format(ostream &os) const {
    os << "Nume: " << nume_client << '\n';
    os << "Masti: " << masti << '\n';
    os << "Dezinfectanti: " << dezinfectanti << '\n';
}

ostream &operator<<(ostream &os, const Achizitie &obj) {
    obj.format(os);
    return os;
}

void Achizitie::adaugaMasca(MascaChirurgicala *masca) {
    // Adaugam la pret aici in functie de eficienta
    if (masca->getFfp() == 0) {
    }

    switch (masca->getFfp()) {
        case 0:
            // masca policarbonat
            total_comenzii += 20;
            break;
        case 1:
            // masca ffp1
            total_comenzii += 5;
            break;
        case 2:
            // masca ffp2
            total_comenzii += 10;
            break;
        case 3:
            // masca ffp3
            total_comenzii += 15;
            break;
        default:
            // implementam un throw daca mai avem timp in caz ca ffp nu apartine {0, 1,2 3}
            // as fi implementat un Enum dar oricum e putin timp
            break;
    }

    masti.push_back(masca);
}

void Achizitie::adaugaDezifectant(Dezinfectant *dezinfectant) {
    // daca e mai mic decat X%
    if (dezinfectant->getEficienta() < .9) {
        total_comenzii += 10;
    } else if (dezinfectant->getEficienta() < .95) {
        total_comenzii += 20;
    } else if (dezinfectant->getEficienta() < .975) {
        total_comenzii += 30;
    } else if (dezinfectant->getEficienta() < .99) {
        total_comenzii += 40;
    } else if (dezinfectant->getEficienta() < .9999) {
        total_comenzii += 50;
    }

    dezinfectanti.push_back(dezinfectant);
}

int main() {
    // Dezinfectant *d = new DezifectantVirusi(12, vector<string>{"apa", "clor"}, vector<string>{"lemn", "marmura"});
    // print(*d);

    // Dezinfectant *d1 = new DezifectantFungi(12, vector<string>{"apa", "clor"}, vector<string>{"lemn", "marmura"});
    // print(*d1);

    DezifectantBacterii *d = new DezifectantBacterii(10000,
                                                     vector<string>{"apa1", "clor1"},
                                                     vector<string>{"marmura1", "lemn1"});

    Achizitie a("Nume Clien Ion");
    a.adaugaDezifectant(d);

    print(*d);

    print(a);
    // nu mai am timp...

    exit(0);
}

/*
Start ora: 9:00, subiectele pe moodle
Se trimite la: examen.oop.fmi@gmail.com pana in ora 11:30
de pe adresa insitutionala.
*/

template <class T>  // functie de get pentru citirea de la tastatura
T get(const string prompt) {
    cout << prompt;  // afisam promptul (mesajul)
    T ret;           // obiectul de return ce trebuie citit
    cin >> ret;
    return ret;
}