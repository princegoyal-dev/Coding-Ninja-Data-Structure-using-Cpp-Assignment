//Program to print number from 1 to a given number n recursively
//Sample input : 9
//Sample output : 1 2 3 4 5 6 7 8 9 
#include <bits/stdc++.h>

using namespace std;

int printN(int num) {
    if(num == 0) {
        return 0;
    }
    printN(num - 1);

    cout << num << " ";
}

int main() {
    int num = 9;

    printN(num);

    return 0;
}