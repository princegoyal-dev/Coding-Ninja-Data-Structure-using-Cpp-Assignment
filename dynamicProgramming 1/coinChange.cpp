#include <bits/stdc++.h>

using namespace std;

int coinChange(int *arr, int size, int sum) {
    if(sum == 0) {
        return 1;
    }
    if(sum < 0) {
        return 0;
    }
    if(size <= 0 && sum >= 1) {
        return 0;
    }
    return coinChange(arr, size - 1, sum) + coinChange(arr, size, sum - arr[size - 1]);
}

int main() {
    int size;
    cin >> size;

    int *arr = new int[size];

    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int sum;
    cin >> sum;

    int result = coinChange(arr, size, sum);
    return 0;
}