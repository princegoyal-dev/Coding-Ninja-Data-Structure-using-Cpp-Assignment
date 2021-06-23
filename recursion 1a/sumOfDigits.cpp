//Program to find the sum of digits of a number using recursion
//Sample input : 12345
//Sample output : 15
#include<bits/stdc++.h>

using namespace std;

int sumDigit(int num) {
    if(num == 0) {
        return 0;
    }
    int lastDigit = num % 10;
    int smallerSum = sumDigit(num/10);

    return lastDigit + smallerSum;
}
int main() {
    int num = 12345;

    int resultSum = sumDigit(num);

    cout << resultSum;
    return 0;
}