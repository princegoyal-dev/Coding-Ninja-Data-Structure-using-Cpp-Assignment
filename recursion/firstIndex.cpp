//Program to find the index of first occurence of a given number in a given array of size n
//Sample input : 1, 2, 3, 4, 5, 6, 4, 5
//Sample size = 8
//Sample num = 6
//Sample output : 5 -> ie. at 5th index the number 6 is present
#include <bits/stdc++.h>

using namespace std;

int findFirstIndex(int *arr, int size, int num) {
    if(size == 0) {
        return -1;
    }
    if(arr[0] == num) {
        return 0;
    }
    int isFoundIndex = findFirstIndex(arr + 1, size - 1, num);

    return isFoundIndex + 1;
}

int main() {
    int size = 8;
    int num = 6;
    int arr[] = {1, 2, 3, 4, 5, 6, 4, 5};
    
    int firstIndex = findFirstIndex(arr, size, num);

    cout << firstIndex << endl;
    
    return 0;
}