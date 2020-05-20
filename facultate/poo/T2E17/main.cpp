#include "Tools.h"
#include "Agenda.h"

using Tools::print;

int main() {
//    Agenda a;

    Abonat_Skype_Romania abonat(1, "Nume", "066060", 31, "mail");

    vector<Abonat_Skype*> c;

    c.push_back(new Abonat_Skype_Romania(1, "name", "055", 12, "mail@"));

    print(c[0]->getMail());
}

//    Persoana p(1, "Nicu");
//    Abonat a(0, std::__cxx11::string(), "10001204");
//    Abonat_Skype(0, std::__cxx11::string(), std::__cxx11::string(), 2);
