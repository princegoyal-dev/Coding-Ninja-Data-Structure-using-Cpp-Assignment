//Program to find triplet sum
//Time complexity : O(n^3)
#include <bits/stdc++.h>

using namespace std;

int tripletSum(int *arr, int size, int sum) {
    int count = 0;
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            for(int k = j + 1; k < size; k++) {
                if(arr[i] + arr[j] + arr[k] == sum) {
                    cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                    count++;
                }
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

    int result = tripletSum(arr, size, sum);
    
    cout << result;
    return 0;
}