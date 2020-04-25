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
    for (auto n : names) {
        if (n.first % 2 == 0) {
            vector<string> v = split(n.second, " ");
            string m = v[0] + "." + v[1] + "@yahoo.com";
            any i = Abonat_Skype_Romania(n.first, n.second, to_string(getRandom(1000000000, 9999999999)), 100 + n.first, m);
            abonati.push_back(i);
        }
        else {
            string country = countries[getRandom(0, countries.size())];
            any i = Abonat_Skype_Extern(n.first, n.second, to_string(getRandom(1000000000, 9999999999)), 100 + n.first, country);
            abonati.push_back(i);
        }
    }
}

ostream &operator<<(ostream &os, const Agenda &obj) {
    for (auto e : obj.abonati) {
        try {
            os << (any_cast<Abonat_Skype_Romania>(e)) << endl;
        }
        catch (exception exc) {
            os << (any_cast<Abonat_Skype_Extern>(e)) << endl;
        }
    }
    return os;
}

vector<any> Agenda::operator[](int id) {
    vector<any> v;
    for (auto e : abonati) {
        try {
            if (any_cast<Abonat_Skype_Romania>(e).getId() == id)
                v.push_back(e);
        }
        catch (exception exc) {
            if (any_cast<Abonat_Skype_Extern>(e).getId() == id)
                v.push_back(e);
        }
    }
    return v;
}

vector<any> Agenda::operator[](string name) {
    vector<any> v;
    for (auto e : abonati) {
        try {
            // desparte numele in 2
            vector<string> n = split(any_cast<Abonat_Skype_Romania>(e).getName(), " ");
            for (auto m_name : n)
                if (m_name == name)
                    v.push_back(e);
        }
        catch (exception exc) {
            // desparte numele in 2
            vector<string> n = split(any_cast<Abonat_Skype_Extern>(e).getName(), " ");
            for (auto m_name : n)
                if (m_name == name)
                    v.push_back(e);
        }
    }
    return v;
}

void Agenda::print(vector<any> v) {
    for (auto e : v){
        try {
            Tools::print(any_cast<Abonat_Skype_Romania>(e));
        }
        catch (exception exc) {
            Tools::print(any_cast<Abonat_Skype_Extern>(e));
        }
    }
}