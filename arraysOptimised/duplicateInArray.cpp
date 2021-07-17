//Program to find duplicate in an array according to given conditions
//Elements in an array are from 0 to n-2
//Only one number is repeated and all are unique
/*
Sample input and output :
    2   
    5
    0 1 2 3 1
    1

    6
    0 1 2 3 4 5
    -1
*/
#include <bits/stdc++.h>

using namespace std;

int findDuplicate(int *arr, int size) {
    int sum = (size - 2) * (size - 1) / (2);
    int sum2 = 0;
    for(int i = 0; i < size; i++) {
        sum2 += arr[i];
    }
    if((sum2 - sum) > (size - 2)) return -1;
    return sum2 - sum;
}

int main() {
    int testCases;
    cin >> testCases;

    while(testCases--) {
        int size;
        cin >> size;

        int *arr = new int[size];

        for(int i = 0; i < size; i++) {
            cin >> arr[i];
        }

        int duplicateNum = findDuplicate(arr, size);

        cout << duplicateNum;

        delete [] arr;
    }
    return 0;
}