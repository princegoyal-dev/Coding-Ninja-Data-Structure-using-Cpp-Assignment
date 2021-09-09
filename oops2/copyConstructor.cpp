#include <bits/stdc++.h>

using namespace std;

class A {
    public :
    int a;
    A(){
        a = 0;
    }
    A(A const &obj) {
        a = obj.a;
    }
    void display() {
        cout << a << endl;
    }
};

int main() {
    A obj1;
    obj1.a = 10;
    A obj2(obj1);
    obj1.display();
    obj2.display();
    return 0;
}