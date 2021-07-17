//find the unique element present in the array among other are present two times in the array
/*
Sample input : 
    1
    5
    1 2 1 2 3
Sample output :
    3   
*/
#include <bits/stdc++.h>

using namespace std;

int findUnique(int *arr, int size) {
    int UniqueNum = arr[0];

    for(int i = 1; i < size; i++) {
        UniqueNum ^= arr[i];
    }

    return UniqueNum;
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

        int UniqueNum = findUnique(arr, size);

        cout << UniqueNum;
        
        delete [] arr;
    
    }

    return 0;
}