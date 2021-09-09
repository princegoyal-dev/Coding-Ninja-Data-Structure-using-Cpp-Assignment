#include <bits/stdc++.h>

using namespace std;

class polynomial {
    private :
        int *coeffArr;
        int capacity;

    public :
        polynomial(int size = 0) {
            if(size == 0) {
                capacity = 10;
            } else {
                capacity = size;
            }
            coeffArr = new int[capacity];
            for(int i = 0; i < capacity; i++) {
                coeffArr[i] = 0;
            }
        }
        polynomial(polynomial const &p) {
            capacity = p.capacity;
            coeffArr = new int[capacity];
            for(int i = 0; i < p.capacity; i++) {
                coeffArr[i] = p.coeffArr[i];
            }
        }
        void setCoeff(int deg, int coeff) {
            if(deg  > capacity - 1) {
                int *newCoeffArr = new int[deg * 2];
                int i;
                for(i = 0; i < capacity; i++) {
                    newCoeffArr[i] = coeffArr[i];
                }
                for(; i < deg * 2; i++) {
                    newCoeffArr[i] = 0;
                }
                delete [] coeffArr;
                coeffArr = newCoeffArr;
                capacity = deg * 2;

            }
            coeffArr[deg] = coeff;
        }
        void add(polynomial p) {
            int bigger = capacity > p.capacity ? capacity : p.capacity;
            int *newCoeffArr = new int[bigger];
            for(int i = 0; i < bigger; i++) {
                if(i < capacity && i < p.capacity) {
                    newCoeffArr[i] = coeffArr[i] + p.coeffArr[i]; 
                } else if(i < capacity && i >= p.capacity) {
                    newCoeffArr[i] = coeffArr[i];
                } else if(i >= capacity && i < p.capacity) {
                    newCoeffArr[i] = p.coeffArr[i];
                }
            }
            delete [] coeffArr;
            coeffArr = newCoeffArr;
            capacity = bigger;
        }
        void printPolynomial() {
            for(int i = 0; i < capacity; i++) {
                if(coeffArr[i] == 0) {
                    continue;
                }
                cout << coeffArr[i] << "x" << i << " ";
            }
            cout << endl;
        }
        polynomial operator + (polynomial p) const {
            int bigger = capacity > p.capacity ? capacity : p.capacity;
            polynomial newPoly(bigger);
            for(int i = 0; i < bigger; i++) {
                if(i < capacity && i < p.capacity) {
                    newPoly.coeffArr[i] = coeffArr[i] + p.coeffArr[i]; 
                } else if(i < capacity && i >= p.capacity) {
                    newPoly.coeffArr[i] = coeffArr[i];
                } else if(i >= capacity && i < p.capacity) {
                    newPoly.coeffArr[i] = p.coeffArr[i];
                }
            }
            return newPoly;
        }
        polynomial operator - (polynomial const &p) {
            int bigger = capacity > p.capacity ? capacity : p.capacity;
            polynomial newPoly(bigger);
            for(int i = 0; i < bigger; i++) {
                if(i < capacity && i < p.capacity) {
                    newPoly.coeffArr[i] = coeffArr[i] - p.coeffArr[i]; 
                } else if(i < capacity && i >= p.capacity) {
                    newPoly.coeffArr[i] = coeffArr[i];
                } else if(i >= capacity && i < p.capacity) {
                    newPoly.coeffArr[i] = -p.coeffArr[i];
                }
            }
            return newPoly;
        }
        polynomial operator * (polynomial const &p) {
            int smaller = capacity < p.capacity ? capacity : p.capacity;
            polynomial newPoly(smaller);
            for(int i = 0; i < smaller; i++) {
                if(i < capacity && i < p.capacity) {
                    newPoly.coeffArr[i] = coeffArr[i] * p.coeffArr[i]; 
                } else {
                    newPoly.coeffArr[i] = 0;
                }
            }
            return newPoly;
        }
        void operator = (polynomial const &p) {
            capacity = p.capacity;
            coeffArr = new int[capacity];
            for(int i = 0; i < p.capacity; i++) {
                coeffArr[i] = p.coeffArr[i];
            }
        }

};
int main() {

    polynomial p1;
    p1.setCoeff(0, 10);
    p1.setCoeff(1, 20);
    p1.setCoeff(2, 30);
    p1.setCoeff(3, 40);
    p1.printPolynomial();

    polynomial p2;
    p2.setCoeff(4, 50);
    p2.setCoeff(3, 60);
    p2.setCoeff(9, 70);
    p2.setCoeff(11, 50);
    p2.printPolynomial();

    // //Adding two polynomial
    // p1.add(p2);
    // p1.printPolynomial();
    
    // //copy contructor
    // polynomial p3(p1);
    // p3.printPolynomial();

    // //overloading + operator
    // polynomial p4 = p1 + p2;
    // p4.printPolynomial();

    // //overloading - operator
    // polynomial p5 = p1 - p2;
    // p5.printPolynomial();

    // //overloading * operator
    // polynomial p6 = p1 * p2;
    // p6.printPolynomial();

    // // overloading = operator
    // polynomial p7;
    // p7 = p1;
    // p7.printPolynomial();
    return 0;
}