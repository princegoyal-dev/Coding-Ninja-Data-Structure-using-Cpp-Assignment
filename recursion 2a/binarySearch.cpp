//Program to implement Binary Search using recursion
//Sample input : {1 ,2, 3, 4, 5, 6, 7, 8, 9}, 3
//Sample output : 2
#include <bits/stdc++.h>

using namespace std;

int binarySearch(int *arr, int si, int ei, int element) {
    if(si > ei) {
        return -1;
    }

    int midIndex = (si + ei) / 2;

    if(arr[midIndex] == element) {
        return midIndex;
    } else if(element < arr[midIndex]) {
        binarySearch(arr, si, midIndex - 1, element);
    } else {
        binarySearch(arr, midIndex + 1, ei, element);
    }
}

int main() {
    int arr[] = {1 ,2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = 3;

    int resultIndex = binarySearch(arr,0, size-1, element);

    cout << resultIndex;
    return 0;
}