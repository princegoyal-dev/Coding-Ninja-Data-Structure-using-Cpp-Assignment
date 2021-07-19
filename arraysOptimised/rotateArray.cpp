#include <bits/stdc++.h>

using namespace std;

void shiftRight(int *arr, int size, int rotations) {
    int *tempArr = new int[size - rotations];
    int j = 0;
    for(int i = size - rotations; i < size; i++, j++) {
        tempArr[j] = arr[i];
    }
    for(int i = size - rotations - 1; i >= 0; i--) {
        arr[i + 2] = arr[i];
    }
    for(int i = 0; i < rotations; i++) {
        arr[i] = tempArr[i];
    }
}

int main() {
    int size;
    cin >> size;

    int *arr = new int[size];

    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int rotations;
    cin >> rotations;

    shiftRight(arr, size, rotations);

    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}