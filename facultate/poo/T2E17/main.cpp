#include "Tools.h"
#include "Agenda.h"

using Tools::print;

class Contact : public Abonat_Skype_Extern, public Abonat_Skype_Romania {

};

int main() {
//    Agenda a;

    Abonat_Skype_Romania abonat(1, "Nume", "066060", 31, "mail");

    vector<Contact*> c;

    c.push_back(new Abonat_Skype_Romania(1, "name", "055", 12, "mail@"));







    my_exit();
}

//    Persoana p(1, "Nicu");
//    Abonat a(0, std::__cxx11::string(), "10001204");
//    Abonat_Skype(0, std::__cxx11::string(), std::__cxx11::string(), 2);
