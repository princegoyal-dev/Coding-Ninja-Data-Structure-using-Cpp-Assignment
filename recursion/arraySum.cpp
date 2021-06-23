//Program to find the sum of a given integer array of size n
//Sample input : 1, 2, 3, 4, 5
//Sample output : 15
#include<bits/stdc++.h>

using namespace std;

int arraySum(int *p, int size) {
    if(size == 0) {
        return 0;
    }

    int smallSum = arraySum(p + 1, size - 1);

    return p[0] + smallSum;
}

int main() {
    int size = 5;
    int p[] = {1, 2, 3, 4, 5};
    int resultSum = arraySum(p, size);

    cout << resultSum << endl;
    return 0;
}