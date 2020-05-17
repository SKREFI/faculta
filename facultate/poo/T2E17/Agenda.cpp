//
// Created by skrefi on 04.04.2020.
//

#include "Agenda.h"


Persoana::Persoana(int id, string name) {
    this->id = id;
    this->name = name;
}

Persoana::Persoana() {}

Abonat::Abonat(int id, string name, string nr_telefon) : Persoana(id, name) {
    this->nr_telefon = nr_telefon;
}

Abonat::Abonat() : Persoana() {}

Abonat_Skype::Abonat_Skype(int id, string name, string nrTelefon, int id_skype) : Abonat(id, name, nrTelefon) {
    this->id_skype = id_skype;
}

Abonat_Skype::Abonat_Skype() : Abonat() {}

Abonat_Skype_Romania::Abonat_Skype_Romania(int id, string name, string nrTelefon, int idSkype, string mail)
        : Abonat_Skype(id, name, nrTelefon, idSkype) {
    this->mail = mail;
}

Abonat_Skype_Romania::Abonat_Skype_Romania() : Abonat_Skype(0, string(), string(), 0) {
    this->mail = string();
}

Abonat_Skype_Extern::Abonat_Skype_Extern(int id, string name, string nrTelefon, int idSkype, string tara)
        : Abonat_Skype(id, name, nrTelefon, idSkype) {
    this->tara = tara;
}

Abonat_Skype_Extern::Abonat_Skype_Extern() : Abonat_Skype() {}

Agenda::Agenda() {
    Abonat a = Abonat(1, "Abonat 1", "07738383");

}

ostream &operator<<(ostream &os, const Agenda &obj) {
    for (auto e : obj.abonati) {
        cout<<e;
    }
    return os;
}

Abonat Agenda::operator[](int i) {
    return this->abonati[i];
}