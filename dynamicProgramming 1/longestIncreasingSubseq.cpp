#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubseq(int *arr, int size, int prev) {
    if(size == 0) {
        return 0;
    }
    if(size == 1) {
        if(arr[0] > prev) {
            return 1;
        } else {
            return 0;
        }
    }
    int result1;
    if(arr[0] < arr[1]) {
        result1 = 2 + longestIncreasingSubseq(arr + 2, size - 2, arr[1]);
    } else {
        result1 = 1 + longestIncreasingSubseq(arr + 2, size - 2, arr[1]);
    }
    return result1;
}

int main() {
    int size;
    cin >> size;

    int *arr = new int[size];
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int result = longestIncreasingSubseq(arr, size, -1);

    cout << result;
    return 0;
}