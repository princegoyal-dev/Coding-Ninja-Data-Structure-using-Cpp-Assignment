#include <bits/stdc++.h>

using namespace std;

void inplacePQ(int *arr, int size) {
    for(int i = 1; i < size; i++) {
        int childIndex = i;
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            if(arr[childIndex] < arr[parentIndex]) {
                int temp = arr[childIndex];
                arr[childIndex] = arr[parentIndex];
                arr[parentIndex] = temp;
            } else break;
            childIndex = parentIndex;
        }
    }
}

int main() {
    int arr[] = {7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    inplacePQ(arr, size);

    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}