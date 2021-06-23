//Program to find x power n ie. x^n 
//Sample input : 9, 3
//Sample output : 729
#include<bits/stdc++.h>

using namespace std;

int xPowerN(int num1, int power) {
    if(power == 1) {
        return num1;
    }
    int smallResult = xPowerN(num1, power-1);

    return (num1 * smallResult);
}

int main() {
    int num1 = 9, power = 3;

    int result = xPowerN(num1, power);
    
    cout << result << endl;
    return 0;
}