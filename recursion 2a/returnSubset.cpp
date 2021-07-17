#include <bits/stdc++.h>

using namespace std;

int returnSubset(int *arr, int size, int **outputArr) {
    if(size == 0) {
        outputArr[0][0] = 0;
        return 1;
    }
    int outputSize = returnSubset(arr + 1, size - 1, outputArr);
    
    for(int i = 0; i < outputSize; i++) {
        int iterSize = outputArr[i][0] + 1;
        outputArr[i + outputSize][0] = arr[0];
        for(int j = 2; j < iterSize + 1 ; j++) {
            outputArr[i + outputSize][j] = outputArr[i][j - 1];
        
        }
    }
    return 2 * outputSize;


}

int main() {
    int size;
    cin >> size;

    int *arr = new int[size];

    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int outputSize = pow(2, size);

    int **outputArr = new int*[outputSize];
    for(int i = 0; i < outputSize; i++) {
        outputArr[i] = new int[size + 1];
    }

    returnSubset(arr, size, outputArr);

    for(int i = 0; i < outputSize; i++) {
        for(int j = 1; j <= outputArr[i][0]; j++) {
            cout << outputArr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}