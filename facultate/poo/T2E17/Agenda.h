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
    string getName() {
        return name;
    }

    int getId() {
        return id;
    }
};

class Abonat : public Persoana {
protected:
    string nr_telefon;

    Abonat(int id, string name, string nr_telefon);

    Abonat();

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

class Agenda {
private:
    vector<string> countries = {"China", "India", "United", "Indonesia", "Brazil", "Pakistan", "Nigeria", "Bangladesh",
                                "Russia", "Japan", "Mexico", "Philippines", "Ethiopia", "Vietnam", "Egypt", "Iran",
                                "Congo,", "Germany", "Turkey", "Thailand", "France", "United", "Italy", "Burma",
                                "South", "Tanzania", "Korea,", "Spain", "Colombia", "Kenya", "Ukraine", "Argentina",
                                "Algeria", "Poland", "Uganda", "Iraq", "Canada", "Morocco", "Afghanistan"};

    vector<pair<int, string>> names = {make_pair(1, "Liam Emma"), make_pair(2, "Noah Olivia"),
                                       make_pair(3, "William Ava"), make_pair(4, "James Isabella"),
                                       make_pair(5, "Oliver Sophia"), make_pair(6, "Benjamin Charlotte"),
                                       make_pair(7, "Elijah Mia"), make_pair(8, "Lucas Amelia"),
                                       make_pair(9, "Mason Harper"), make_pair(10, "Logan Evelyn"),
                                       make_pair(11, "Alexander Abigail"), make_pair(12, "Ethan Emily"),
                                       make_pair(13, "Jacob Elizabeth"), make_pair(14, "Michael Mila"),
                                       make_pair(15, "Daniel Ella"), make_pair(16, "Henry Avery"),
                                       make_pair(17, "Jackson Sofia"), make_pair(18, "Sebastian Camila"),
                                       make_pair(19, "Aiden Aria"), make_pair(20, "Matthew Scarlett"),
                                       make_pair(21, "Samuel Victoria"), make_pair(22, "David Madison"),
                                       make_pair(23, "Joseph Luna"), make_pair(24, "Carter Grace"),
                                       make_pair(25, "Owen Chloe"), make_pair(26, "Wyatt Penelope"),
                                       make_pair(27, "John Layla"), make_pair(28, "Jack Riley"),
                                       make_pair(29, "Luke Zoey"), make_pair(30, "Jayden Nora"),
                                       make_pair(31, "Dylan Lily"), make_pair(32, "Grayson Eleanor"),
                                       make_pair(33, "Levi Hannah"), make_pair(34, "Isaac Lillian"),
                                       make_pair(35, "Gabriel Addison"), make_pair(36, "Julian Aubrey"),
                                       make_pair(37, "Mateo Ellie"), make_pair(38, "Anthony Stella"),
                                       make_pair(39, "Jaxon Natalie"), make_pair(40, "Lincoln Zoe"),
                                       make_pair(41, "Joshua Leah"), make_pair(42, "Christopher Hazel"),
                                       make_pair(43, "Andrew Violet"), make_pair(44, "Theodore Aurora"),
                                       make_pair(45, "Caleb Savannah"), make_pair(46, "Ryan Audrey"),
                                       make_pair(47, "Asher Brooklyn"), make_pair(48, "Nathan Bella"),
                                       make_pair(49, "Thomas Claire"), make_pair(50, "Leo Skylar"),
                                       make_pair(51, "Isaiah Lucy"), make_pair(52, "Charles Paisley"),
                                       make_pair(53, "Josiah Everly"), make_pair(54, "Hudson Anna"),
                                       make_pair(55, "Christian Caroline"), make_pair(56, "Hunter Nova"),
                                       make_pair(57, "Connor Genesis"), make_pair(58, "Eli Emilia"),
                                       make_pair(59, "Ezra Kennedy"), make_pair(60, "Aaron Samantha"),
                                       make_pair(61, "Landon Maya"), make_pair(62, "Adrian Willow"),
                                       make_pair(63, "Jonathan Kinsley"), make_pair(64, "Nolan Naomi"),
                                       make_pair(65, "Jeremiah Aaliyah"), make_pair(66, "Easton Elena"),
                                       make_pair(67, "Elias Sarah"), make_pair(68, "Colton Ariana"),
                                       make_pair(69, "Cameron Allison"), make_pair(70, "Carson Gabriella"),
                                       make_pair(71, "Robert Alice"), make_pair(72, "Angel Madelyn"),
                                       make_pair(73, "Maverick Cora"), make_pair(74, "Nicholas Ruby"),
                                       make_pair(75, "Dominic Eva"), make_pair(76, "Jaxson Serenity"),
                                       make_pair(77, "Greyson Autumn"), make_pair(78, "Adam Adeline"),
                                       make_pair(79, "Ian Hailey"), make_pair(80, "Austin Gianna"),
                                       make_pair(81, "Santiago Valentina"), make_pair(82, "Jordan Isla"),
                                       make_pair(83, "Cooper Eliana"), make_pair(84, "Brayden Quinn"),
                                       make_pair(85, "Roman Nevaeh"), make_pair(86, "Evan Ivy"),
                                       make_pair(87, "Ezekiel Sadie"), make_pair(88, "Xavier Piper"),
                                       make_pair(89, "Jose Lydia"), make_pair(90, "Jace Alexa"),
                                       make_pair(91, "Jameson Josephine"), make_pair(92, "Leonardo Emery"),
                                       make_pair(93, "Bryson Julia"), make_pair(94, "Axel Delilah"),
                                       make_pair(95, "Everett Arianna"), make_pair(96, "Parker Vivian"),
                                       make_pair(97, "Kayden Kaylee"), make_pair(98, "Miles Sophie"),
                                       make_pair(99, "Sawyer Brielle"), make_pair(100, "Jason Madeline")};

    vector<any> abonati;
public:
    Agenda();
    friend ostream &operator<<(ostream &os, const Agenda &obj);
    vector<any> operator[](int);
    vector<any> operator[](string);
    void print(vector<any> v);
};