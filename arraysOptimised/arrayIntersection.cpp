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

int findIntersection(int *arr1, int size1, int *arr2, int size2 , int *outputArr, int smallerSize) {
    mergeSort(arr1, 0, size1 - 1);
    mergeSort(arr2, 0, size2 - 1);
    int i = 0;
    int j = 0;
    int k = 0;
    for(int i = 0; i < size2; i++) {
        if(arr2[i] < arr1[j]) {
            i++; 
        } else if(arr2[i] > arr1[j]) {
            j++;
        } else {
            outputArr[k] = arr1[i];
            i++;
            j++;
            k++;
        }
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