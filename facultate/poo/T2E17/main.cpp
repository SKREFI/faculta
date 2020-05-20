#include "Tools.h"
#include "Agenda.h"

using Tools::print;

vector<string> tari = {"USA", "UK", "Spain", "France", "Germany", "China"};
vector<string> names = {"Liam", "Emma", "Olivia", "Isabella", "James", "William", "Ava", "Noah"};

Abonat_Skype_Romania *getRandomASR() {
    return new Abonat_Skype_Romania(getRandom(0, 10001), "name" + to_string(getRandom(1, 100)),
                                    to_string(getRandom(1000000000, 9000000000)), getRandom(10, 1000),
                                    names[getRandom(0, names.size())] + "@gmail.com");
}

Abonat_Skype_Extern *getRandomASE() {
    return new Abonat_Skype_Extern(getRandom(0, 10001), "name" + to_string(getRandom(1, 100)),
                                   to_string(getRandom(1000000000, 9000000000)), getRandom(10, 1000),
                                   tari[getRandom(0, tari.size())]);
}


int main() {
    srand(time(NULL));

    Agenda a;
    a.addContact(getRandomASE());
    a.addContact(getRandomASE());
    a.addContact(getRandomASR());

//
//    print(a.getContact(2)->getCountry());
//    print(a.getContact(2)->getCountry());
//    print(a.getContact(1)->getMail());
//    print(a.getContact(0)->getMail());

    for (int i = 0; i < a.size(); i++) {
        try {
            print(a.getContact(i)->getCountry(), "", " ");
            print(a.getContact(i)->getMail());
        }
        catch (logic_error l) {
            print("123");
        }
    }
}

//    Persoana p(1, "Nicu");
//    Abonat a(0, std::__cxx11::string(), "10001204");
//    Abonat_Skype(0, std::__cxx11::string(), std::__cxx11::string(), 2);
