#include<bits/stdc++.h>

using namespace std;

int mult(int num1, int num2) {
    if(num2 == 0 || num1 == 0) {
        return 0;
    }
    int smallMulOutput = mult(num1, num2 - 1);
    return (num1 + smallMulOutput);
}

int main() {
    int num1 = 10;
    int num2 = 0;
    int result = mult(num1, num2);
    cout << result << endl;
    
    return 0;
}