//Program to check whether a given number is present in the given array or not
//Sample input : 
//    5 -> size of the array
//    3 -> Number to be found
//    1 2 3 4 5   -> array
//Sample output : true
#include <bits/stdc++.h>

using namespace std;

bool findN(int *p, int size, int num) {
    if(size == 0) {
        return false;
    }
    bool isFound, result;
    if(p[0] == num) {
        result = true;
        return true;
    } else {
        isFound = findN(p + 1, size - 1, num);
    }
    return result || isFound;
}

int main() {
    int size = 5;
    int x = 6;
    int p[] = {1, 2, 3, 4, 5};

    bool isFound = findN(p, size, x);

    cout << boolalpha << isFound << endl;
    return 0;
}