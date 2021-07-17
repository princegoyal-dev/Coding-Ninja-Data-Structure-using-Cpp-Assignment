#include <bits/stdc++.h>

using namespace std;

int main() {
    int **arr = new int*[10];
    int arr[0] = new int[5];
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 2; j++) {
            cout << arr[i][j] << " ";
        }
    }
     
    return 0;
}