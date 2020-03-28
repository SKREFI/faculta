#include <iostream>
using namespace std;

class Log {
    int info;

   public:
    static void fail(string str) { cout << str; }
};

int main() {
    Log.fail("ASD");

    Log l;
    l.fail("asd");
    cout << "\n\n";
}