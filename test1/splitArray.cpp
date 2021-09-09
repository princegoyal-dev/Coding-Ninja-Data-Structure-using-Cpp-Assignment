//reference : https://www.geeksforgeeks.org/split-the-array-into-equal-sum-parts-according-to-given-conditions/
#include <bits/stdc++.h>

using namespace std;

bool helper(int *arr, int size, int start, int lsum, int rsum) {
    if(start == size) {
        return lsum == rsum;
    }

    if(arr[start] % 5 == 0) {
        lsum += arr[start];
    } else if(arr[start] % 3 == 0) {
        rsum += arr[start];
    } else {
        return helper(arr, size, start + 1, lsum + arr[start], rsum) || helper(arr, size, start + 1, lsum, rsum + arr[start]);
    }
    // return helper(arr, size, start + 1, lsum, rsum);
}
bool splitArray(int *arr, int size) {
    return helper(arr, size, 0, 0, 0);
}
 
int main() {
    int size;
    cin >> size;

    int *arr = new int[size];

    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    if(splitArray(arr, size)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}