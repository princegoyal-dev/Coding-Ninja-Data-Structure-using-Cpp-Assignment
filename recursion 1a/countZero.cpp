//Program to count number of zeros in a given number
//Sample input : 100980970
//Sample output : 4
#include<bits/stdc++.h>

using namespace std;

int countZero(int n) {
    int count = 0;
    if(n == 0) {
        return 0;
    }
    if(n % 10 == 0) {
        count = 1;
    }
    return(count + countZero(n/10));
}

int main() {
    int n = 1034501000;

    int result = countZero(n);

    cout << result;

    return 0;
}