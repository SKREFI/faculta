#include <bits/stdc++.h>
using namespace std;

template <class T>
void print(T x, string sep = " ", string end = "\n") {
    cout << x << sep << end;
}

void exit() { print("\n\nDONE"); }

struct Node {
   private:
    int data;
    struct Node* next;

   public:
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    int getData() { return this->data; }
    void setNext(Node* n) { this->next = n; }
    Node* getNext() { return this->next; }
};

int main() {
    Node head(1);
    print(head.getData());
    Node second(2);
    head.setNext(&second);
    print(head.getNext().getData());

    exit();
}
