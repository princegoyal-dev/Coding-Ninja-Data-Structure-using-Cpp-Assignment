#include <bits/stdc++.h>

using namespace std;

template <typename T>

class Pair {
    T x;
    T y;

    public :
        void setX(T value) {
            x = value;
        }
        void setY(T value) {
            y = value;
        }
        T getX() {
            return x;
        }
        T getY() {
            return y;
        }
};

template <typename T, typename V>
class Pair2 {
    T x;
    V y;

    public : 
        void setX(T value) {
            x = value;
        }
        void setY(V value) {
            y = value;
        }
        T getX() {
            return x;
        }
        V getY() {
            return y;
        }
};

int main() {
    // Pair <int> p;
    // p.setX(10);
    // p.setY(20);

    // cout << p.getX() << endl;
    // cout << p.getY() << endl;
    
    // Pair2 <int, double> p2;
    // p2.setX(10);
    // p2.setY(20.5);

    // cout << p2.getX() << endl;
    // cout << p2.getY() << endl;

    Pair <Pair <int>> p3;
    
    Pair <int> p3_1;
    p3_1.setX(30);
    p3_1.setY(40);
    cout << p3_1.getX() << endl;
    cout << p3_1.getY() << endl;

    Pair <int> p3_2;
    p3_2.setX(50);
    p3_2.setY(60);
    cout << p3_2.getX() << endl;
    cout << p3_2.getY() << endl;

    p3.setX(p3_1);
    p3.setY(p3_2);
    cout << p3.getX().getX() << endl;
    cout << p3.getX().getY() << endl;
    cout << p3.getY().getX() << endl;
    cout << p3.getY().getY() << endl;
    
    return 0;
}