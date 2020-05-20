#pragma once

#include <any>
#include "Tools.h"

/*
        Persoana(id, nume)
         ---Abonat(nr_telefon)
             ---Abonat_Skype(id_skype)
                 ---Abonat_Skype_Romania(adresa_mail)
                 ---Abonat_Skype_Extern(tara)
*/

class Persoana {
protected:
    int id;
    string name;

    Persoana(int id, string name);

    friend ostream& operator<<(ostream &os, const Persoana &p);

    Persoana();
public:
    virtual string getName() {
        return name;
    }

    int getId() {
        return id;
    }
};

class Abonat : public Persoana {
protected:
    string nr_telefon;

    Abonat();

    Abonat(int id, string name, string nr_telefon);

public:
    string getPhone() {
        return nr_telefon;
    }
};

class Abonat_Skype : public Abonat {
protected:
    int id_skype;

    Abonat_Skype(int id, string name, string nrTelefon, int id_skype);

    Abonat_Skype();

public:
    int getSkypeId() {
        return id_skype;
    }
};

class Abonat_Skype_Romania : public Abonat_Skype {
private:
    string mail;
public:
    Abonat_Skype_Romania(int id, string name, string nrTelefon, int idSkype, string mail);

    Abonat_Skype_Romania();

    string getMail() {
        return mail;
    }

    friend ostream &operator<<(ostream &os, const Abonat_Skype_Romania &obj) {
        os << obj.id << ' ' << obj.name << ' ' << obj.nr_telefon << ' ' << obj.id_skype << ' ' << obj.mail;
        return os;
    }

    friend istream &operator>>(istream &is, Abonat_Skype_Romania &obj) {
        is >> obj.id >> obj.name >> obj.nr_telefon >> obj.id_skype >> obj.mail;
        return is;
    }
};

class Abonat_Skype_Extern : public Abonat_Skype {
private:
    string tara;
public:
    Abonat_Skype_Extern(int id, string name, string nrTelefon, int idSkype, string tara);

    Abonat_Skype_Extern();

    string getCountry() {
        return tara;
    }

    friend ostream &operator<<(ostream &os, const Abonat_Skype_Extern &obj) {
        os << obj.id << ' ' << obj.name << ' ' << obj.nr_telefon << ' ' << obj.id_skype << ' ' << obj.tara;
        return os;
    }

    friend istream &operator>>(istream &is, Abonat_Skype_Extern &obj) {
        is >> obj.id >> obj.name >> obj.nr_telefon >> obj.id_skype >> obj.tara;
        return is;
    }
};

