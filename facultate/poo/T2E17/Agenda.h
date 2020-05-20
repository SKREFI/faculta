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

    friend ostream &operator<<(ostream &os, const Persoana &p);

public:
    virtual string getName() { return name; }

    int getId() { return id; }
};

class Abonat : public Persoana {
protected:
    string nr_telefon;

    Abonat(int id, string name, string nr_telefon);

public:
    string getPhone() { return nr_telefon; }
};

class Abonat_Skype : public Abonat {
protected:
    int id_skype;

    Abonat_Skype(int id, string name, string nrTelefon, int id_skype);

public:
    int getSkypeId() { return id_skype; }

    friend ostream &operator<<(ostream &out, const Abonat_Skype &obj) {
        obj.format(out);
        return out;
    }

    virtual void format(ostream &out) const { out << id << ' ' << name << ' ' << nr_telefon << ' ' << id_skype; }

    virtual string getMail() {};

    virtual string getCountry() {};
};

class Abonat_Skype_Romania : public Abonat_Skype {
private:
    string mail;
public:
    Abonat_Skype_Romania(int id, string name, string nrTelefon, int idSkype, string mail);

    friend ostream &operator<<(ostream &out, const Abonat_Skype_Romania &obj) {
        obj.format(out);
        return out;
    }

    void format(ostream &out) const override {
        out << id << ' ' << name << ' ' << nr_telefon << ' ' << id_skype << ' ' << mail;
    }

    string getMail() override { return mail; }

    string getCountry() { return NULL; };

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

    friend ostream &operator<<(ostream &out, const Abonat_Skype_Extern &obj) {
        obj.format(out);
        return out;
    }

    void format(ostream &out) const override {
        out << id << ' ' << name << ' ' << nr_telefon << ' ' << id_skype << ' ' << tara;
    }

    string getCountry() override { return tara; }

    string getMail() {};

    friend istream &operator>>(istream &is, Abonat_Skype_Extern &obj) {
        is >> obj.id >> obj.name >> obj.nr_telefon >> obj.id_skype >> obj.tara;
        return is;
    }
};


class Agenda {
private:
    vector<Abonat_Skype *> contacts;
public:
    void addContact(Abonat_Skype_Romania *a) { this->contacts.push_back(a); }

    void addContact(Abonat_Skype_Extern *a) { this->contacts.push_back(a); }

    vector<Abonat_Skype *> getContacts() { return contacts; };

    Abonat_Skype *getContact(int index);

    void removeContact(int index) {
        try {
            if (index < 0 || index >= this->contacts.size())
                throw string("Index of out range!");

            else
                contacts.erase(contacts.begin() + index);
        }
        catch (string &s) {
            cout << s << '\n';
        }
    }

    int size() {
        return contacts.size();
    }
};