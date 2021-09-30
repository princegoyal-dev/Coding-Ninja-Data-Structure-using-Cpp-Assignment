#include <bits/stdc++.h>

using namespace std;

int maxZeroSquareMatrix(int **arr, int n, int m) {

    int **newArr = new int*[n];
    for(int i = 0; i < n; i++) {
        newArr[i] = new int[m];
        for(int j = 0; j < m; j++) {
            newArr[i][j] = -1;
        }
    }

    for(int i = 0; i < n; i++) {
        if(arr[i][0] == 0) {
            newArr[i][0] = 1;
        } else {
            newArr[i][0] = 0;
        }
    }
    for(int i = 0; i < m; i++) {
        if(arr[0][i] == 0) {
            newArr[0][i] = 1;
        } else {
            newArr[0][i] = 0;
        }
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(arr[i][j] == 1) {
                newArr[i][j] = 0;
                continue;
            }
            if(arr[i][j] == 0) {
                int option1 = newArr[i - 1][j];
                int option2 = newArr[i][j - 1];
                int option3 = newArr[i - 1][j - 1];
                newArr[i][j] = min(option1, min(option2, option3)) + 1;
            }
        }
    }

    int count = INT_MIN;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(count < newArr[i][j]) {
                count = newArr[i][j];
            }
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    int **arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int result = maxZeroSquareMatrix(arr, n, m);

    cout << result;
    return 0;
}