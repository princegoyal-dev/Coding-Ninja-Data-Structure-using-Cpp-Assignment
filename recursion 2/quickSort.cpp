#include <bits/stdc++.h>

using namespace std;

int partition(int *arr, int si, int ei) {
    int countLesser = 0;
    for(int i = 1; i <= ei; i++) {
        if(arr[i] <= arr[si]) {
            countLesser++;
        }
    }
    int pivotIndex = countLesser;
    int temp = arr[pivotIndex];
    arr[pivotIndex] = arr[si];
    arr[si] = temp;

    int i = 0;
    int j = ei;
    while(i < pivotIndex) {
        bool flag = false;
        if(arr[i] > arr[pivotIndex]) {
            while(j > pivotIndex) {
                if(arr[j] <= arr[pivotIndex]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    flag = true;
                }
                j--;
                if(flag == true) {
                    break;
                }
            }
        }
        i++;
    }
    return pivotIndex;
}

void quickSort(int *arr, int si, int ei) {
    if(si >= ei) {
        return;
    }
    int index = partition(arr, si, ei);
    quickSort(arr, si, index - 1);
    quickSort(arr, index + 1, ei);
}

int main() {
    int arr[] = {5, 13, 14, 3, 7, 8, 12, 4, 6, 1, 9, 2, 10, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, size - 1);

    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}