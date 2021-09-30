#include <bits/stdc++.h>

using namespace std;

int matrixChainMul(int *arr, int si, int ei) {
    if(si == ei) {
        cout << "si == ei : " << si << " " << ei << endl;
        return 0;
    }
    cout << "si : " << si << " ei : " << ei << endl;
    int result = 0;
    int count = INT_MAX;
    for(int k = si; k < ei; k++) {
        cout << "k : " << k << endl;
        result = matrixChainMul(arr, si, k) + matrixChainMul(arr, k + 1, ei) + (arr[si - 1] * arr[k] * arr[ei]);
        cout << "result : " << result << endl;
        cout << "countPrevious : " << count << endl;
        if(result < count) {
            count = result;
        }
        cout << "count : " << count << endl;
    }
    return count;
}

int main() {
    int size;
    cin >> size;

    int *arr = new int[size + 1];

    for(int i = 0; i <= size; i++) {
        cin >> arr[i];
    }

    int result = matrixChainMul(arr, 1, size);
    cout << result;
    return 0;
}