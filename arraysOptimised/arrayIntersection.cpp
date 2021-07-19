#include <bits/stdc++.h>

using namespace std;

void merge(int *a, int si, int midIndex, int ei) {
    int i = si;
    int j = midIndex + 1;
    int k = si;
    int b[ei + 1];
    while(i <= midIndex && j <= ei) {
        if(a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if(i > midIndex) {
        while(j <= ei) {
            b[k] = a[j];
            j++;
            k++;
        }
    } else {
        while(i <= midIndex) {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    for(k = si; k <= ei; k++) {
        a[k] = b[k];
    }
}

void mergeSort(int *arr, int si, int ei) {
    if(si >= ei) {
        return;
    }
    int midIndex = (si + ei) / 2;
    mergeSort(arr, si, midIndex);
    mergeSort(arr, midIndex + 1, ei);
    merge(arr, si, midIndex, ei);
}

void printArray(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findIntersection(int *arr1, int size1, int *arr2, int size2 , int *outputArr, int smallerSize) {
    mergeSort(arr1, 0, size1 - 1);
    mergeSort(arr2, 0, size2 - 1);
    printArray(arr1, size1);
    printArray(arr2, size2);
    int i = 0;
    int j = 0;
    int k = 0;
    string limit = size1 < size2 ? "array1" : "array2";
    if(limit == "array2") {
        int *temp = arr1;
        arr1 = arr2;
        arr2 = temp;
        int tempSize = size1;
        size1 = size2;
        size2 = tempSize;
    }

    printArray(arr1, size1);
    printArray(arr2, size2);
    for(i = 0; i < size1; i++) {
        if(arr1[i] == arr2[j]) {
            outputArr[k] = arr1[i];
            k++;
            j++;
            continue;
        } else if(arr1[i] < arr2[j]) {
            outputArr[k] = arr1[i];
            k++;    
        } else {
            outputArr[k] = arr2[j];
            j++;
            k++;
            i--;
        }
    }
    for(; j < size2; j++) {
        outputArr[k] = arr2[j];
        k++;
    }
    return k;
}

int main() {
    int testCases;
    cin >> testCases;

    while(testCases--) {
        int size1;
        cin >> size1;

        int *arr1 = new int[size1];

        for(int i = 0; i < size1; i++) {
            cin >> arr1[i];
        }
        
        int size2;
        cin >> size2;

        int *arr2 = new int[size2];

        for(int i = 0; i < size2; i++) {
            cin >> arr2[i];
        }

        int smallerSize = size1 < size2 ? size1 : size2;

        int *outputArr = new int[smallerSize];

        int lastIndex = findIntersection(arr1, size1, arr2, size2, outputArr, smallerSize);

        for(int i = 0; i < lastIndex; i++) {
            cout << outputArr[i] << " ";
        }

        delete [] arr1;
        delete [] arr2;
    }
    return 0;
}