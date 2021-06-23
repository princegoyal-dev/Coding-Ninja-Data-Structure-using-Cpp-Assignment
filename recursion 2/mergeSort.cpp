#include<bits/stdc++.h>

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

int main() {
    int arr[] = {1, 3, 5, 4, 2, 6, 8, 9, 7, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);

    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}