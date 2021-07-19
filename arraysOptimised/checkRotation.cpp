#include <bits/stdc++.h>

using namespace std;

int checkRotation(int *arr, int size) {
    int count = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] > arr[i + 1]) {
            count++;
            break;
        } else {
            count++;
        }
    }
    return count;
}
int main() {
    int size;
    cin >> size;

    int *arr = new int[size];

    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int result = checkRotation(arr, size);

    cout << result;
    return 0;
}