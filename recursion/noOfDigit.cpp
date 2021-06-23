//Program to find number of digits in a given number
//Sample input : 123232
//Sample output : 6
#include<bits/stdc++.h>

using namespace std;

int countDigit(int num) {
    if(num == 0) {
        return 0;
    }
    int count = 0;
    count = countDigit(num / 10);

    return ++count;
}

int main() {
    int num = 123232;

    int resultCount = countDigit(num);

    cout << resultCount;
    return 0;
}