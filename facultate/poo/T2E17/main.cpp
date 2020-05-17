#include "Tools.h"
#include "Agenda.h"

using Tools::print;

int main() {
    Agenda a;
    vector<any> results = a["Cooper"];
    results = extend(results, a[-1]);
    a.print(results);

    my_exit();
}

//    Persoana p(1, "Nicu");
//    Abonat a(0, std::__cxx11::string(), "10001204");
//    Abonat_Skype(0, std::__cxx11::string(), std::__cxx11::string(), 2);
