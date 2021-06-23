//Program to get all the occurences of a given number in given array of size n
/* Sample input : 1, 2, 3, 6, 7, 8, 5, 6, 4, 12, 7, 9, 0, 7, 6, 3
    size = 16;
    num = 6
    outputArray of same size having -1 at all the places

   Sample output : -1 -1 -1 3 -1 -1 -1 7 -1 -1 -1 -1 -1 -1 14 -1
*/
#include<bits/stdc++.h>

using namespace std;

int printAllOccurences(int *arr, int size, int num, int *outputArr) {
    if(size == 0) {
        return -1;
    }

    int nextIndex = printAllOccurences(arr, size - 1, num, outputArr);

    if(arr[size - 1] == num) {
        outputArr[size - 1] = size - 1;
    }
}

int main() {
    int size = 16;
    int num = 6;
    int arr[] = {1, 2, 3, 6, 7, 8, 5, 6, 4, 12, 7, 9, 0, 7, 6, 3};
    int outputArr[size];

    for(int i = 0; i < size; i++) {
        outputArr[i] = -1;
    }

    printAllOccurences(arr, size, num, outputArr);

    for(int i = 0; i < size; i++) {
        cout << outputArr[i] << " ";
    }

    return 0;
}