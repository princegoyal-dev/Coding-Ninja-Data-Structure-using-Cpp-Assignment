//Program to find the geometric sum of 1/2^n
//sample input : 11
//sample output : 1.99951
#include <bits/stdc++.h>

using namespace std;

double geoSum(int n) {
    if(n == 0) {
        return 1;
    }
    double smallCalc = geoSum(n-1);

    return ((1/pow(2,n)) + smallCalc);
}

int main() {
    int n = 11;

    double result = geoSum(n);

    cout << result;
    return 0;
}