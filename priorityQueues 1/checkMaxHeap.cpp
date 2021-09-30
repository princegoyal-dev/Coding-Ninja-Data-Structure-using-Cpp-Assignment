#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    int *arr = new int[size];

    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    bool flag = false;    
    for(int i = 1; i < size; i++) {
        int childIndex = i;
        int parentIndex = (childIndex - 1) / 2;
        if(arr[parentIndex] < arr[childIndex]) {
            cout << false;
            flag = true;
            break;
        }
    }

    if(flag == false) {
        cout << true;
    }
    return 0;
}