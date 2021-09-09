#include <bits/stdc++.h>

using namespace std;

class Fraction {
    int numerator;
    int denominator;

    public:
        Fraction() {
            numerator = 0;
            denominator = 0;
        }
        Fraction(int num, int den) {
            numerator = num;
            denominator = den;
            simplify();
        }
        Fraction(int num) {
            numerator = num;
            denominator = 1;
        }

        void simplify() {
            int hcf = 1;
            bool numNegative = false;
            if(this -> numerator < 0) {
                numNegative = true;
                this -> numerator =  -(this -> numerator);
            }
            int smaller = this -> numerator < this -> denominator ? this -> numerator : this -> denominator;
            for(int i = 2; i <= smaller; i++) {
                if(this -> numerator % i == 0 && this -> denominator % i == 0) {
                    hcf = i;
                }
            }
            if(numNegative) {
                this -> numerator = -(this -> numerator);
            }
            this -> numerator /= hcf;
            this -> denominator /= hcf;
        } 

        int getNum() {
            return numerator;
        }

        int getDen() {
            return denominator;
        }

        void display() const {
            cout << numerator << " / " << denominator;
            cout << endl;
        }
        void add(Fraction const &f2) {
            int lcm = this -> denominator * f2.denominator;
            int numerator = ((this -> numerator) * (lcm / (this -> denominator))) + ((f2.numerator) * (lcm / (f2.denominator)));
            this -> numerator = numerator;
            this -> denominator = lcm;
            simplify();
        }
        void multiply(Fraction const &f2) {
            this -> numerator *= f2.numerator;
            this -> denominator *= f2.denominator;
            simplify();
        }
        void subtract(Fraction const &f2) {
            int lcm = this -> denominator * f2.denominator;
            int numerator = ((this -> numerator) * (lcm / (this -> denominator))) - ((f2.numerator) * (lcm / (f2.denominator)));
            this -> numerator = numerator;
            this -> denominator = lcm;
            simplify();
        }
        Fraction operator + (Fraction const &f2) const {
            int lcm = this -> denominator * f2.denominator;
            int numerator = ((this -> numerator) * (lcm / (this -> denominator))) + ((f2.numerator) * (lcm / (f2.denominator)));
            Fraction f(numerator, lcm);
            f.simplify();
            return f;
        }
        Fraction operator - (Fraction const &f2) const {
            int lcm = this -> denominator * f2.denominator;
            int numerator = ((this -> numerator) * (lcm / (this -> denominator))) - ((f2.numerator) * (lcm / (f2.denominator)));
            Fraction f(numerator, lcm);
            f.simplify();
            return f;
        }
        Fraction operator * (Fraction const &f2) const {
            Fraction f((this -> numerator) * f2.numerator, (this -> denominator) * f2.denominator);
            f.simplify();
            return f;
        }
        Fraction& operator ++ () {
            this -> numerator += this -> denominator;
            return *this;
        }
        Fraction operator ++ (int) {
            Fraction f(this -> numerator, this -> denominator);
            this -> numerator += this -> denominator;
            return f;
        }
};

int main() {
    Fraction f1(20, 5);
    f1.display();
    Fraction f2(40, 3);
    f2.display();
    
    // // Adding two fractions
    // f1.add(f2);
    // f1.display();

    // // Multiplying two fractions
    // f1.multiply(f2);
    // f1.display();

    // //Subtracting two fractions
    // f1.subtract(f2);
    // f1.display();

    // // +operator overloading
    // Fraction f3 = f1 + f2;
    // f3.display();

    // -operator overloaded
    // Fraction f4 = f1 - f2;
    // f4.display();

    // *operator overloaded
    // Fraction f5 = f1 * f2;
    // f5.display();

    // // ++ pre-increment operator
    // Fraction f6 = ++(++(++f2));
    // f6.display();

    // ++ post-increment operator
    Fraction f7 = f2++;
    f7.display();
    f2.display();

    return 0;
}