#include <bits/stdc++.h>

using namespace std;

int findPairSum(int *arr, int size, int sum) {
    int count = 0;
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] + arr[j] == sum) {
                cout << arr[i] << " " << arr[j] << endl;
                count++;
            }
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
    int sum;
    cin >> sum;

    int result = findPairSum(arr, size, sum);

    cout << result;
    return 0;
}