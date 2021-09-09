//program to find the price of the app such that you will get the maximum profit
/* 
sample input: 
    5
    34 78 90 15 67
sample output:
    201
*/
#include <bits/stdc++.h>

using namespace std;

void merge(int *a, int si, int midIndex, int ei) {
    int i = si;
    int j = midIndex + 1;
    int k = si;
    int tempArr[ei + 1];
    while(i <= midIndex && j <= ei) {
        if(a[i] <= a[j]) {
            tempArr[k] = a[i];
            i++;
            k++;
        } else {
            tempArr[k] = a[j];
            k++;
            j++;
        }
    }
    if(i > midIndex) {
        while(j <= ei) {
            tempArr[k] = a[j];
            j++;
            k++;
        }
    } else {
        while(i <= midIndex) {
            tempArr[k] = a[i];
            i++;
            k++;
        }
    }
    for(k = si; k <= ei; k++) {
        a[k] = tempArr[k];
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

int getMaximumProfit(int *arr, int size) {
    mergeSort(arr, 0, size - 1);
    int tempArr[size];
    int tempSize = size;
    for(int i = 0; i < size; i++) {
        tempArr[i] = arr[i] * tempSize;
        if(tempSize > 1) {
            tempSize--;
        }
    }
    int j = 0;
    int maxElement = INT_MIN;
    int maxIndex = -1;
    // for(int i = 0; i < size; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < size; i++) {
    //     cout << tempArr[i] << " ";
    // }
    // cout << endl;
    for(; j < size; j++) {
        if(tempArr[j] > maxElement) {
            maxElement = tempArr[j];
            maxIndex = j;
        }
    }
    // return arr[maxIndex]; to retrieve the price of the app
    return *max_element(tempArr, tempArr + (size - 1));
}

int main() {
    int buyers;
    cin >> buyers;

    int *arr = new int[buyers];

    for(int i = 0; i < buyers; i++) {
        cin >> arr[i];
    }

    int result = getMaximumProfit(arr, buyers);

    cout << result;
    return 0;
}