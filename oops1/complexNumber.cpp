#include <bits/stdc++.h>

using namespace std;

class ComplexNumbers {
    int real;
    int imag;
    
    public:
        ComplexNumbers() {
            real = 0;
            imag = 0;
        }
        ComplexNumbers(int real, int imag) {
            this -> real = real;
            this -> imag = imag;
        }
        void display() {
            cout << real;
            if(imag >= 0) {
                cout << " + ";
            }
            bool isNegative = false;
            if(imag < 0) {
                cout << " - ";
                imag = -(imag);
                isNegative = true;
            }
            cout << imag << "i";
            cout << endl;
            if(isNegative) {
                imag = -(imag);
            }
        }
        void add(ComplexNumbers const &c) {
            this -> real += c.real;
            this -> imag += c.imag;
        }
        void sub(ComplexNumbers const &c) {
            this -> real -= c.real;
            this -> imag -= c.imag;
        }
        void multiply(ComplexNumbers const &c) {
            this -> real *= c.real;
            this -> imag *= c.imag;
        }
};

int main() {
    ComplexNumbers c1(20, 30);
    ComplexNumbers c2(40, -50);

    c1.display();
    c2.display();

    //adding two complex numbers
    c1.add(c2);
    c1.display();

    //subtracting two complex numbers
    c1.sub(c2);
    c1.display();

    //multiplying two complex numbers
    c1.multiply(c2);
    c1.display();

    return 0;
}