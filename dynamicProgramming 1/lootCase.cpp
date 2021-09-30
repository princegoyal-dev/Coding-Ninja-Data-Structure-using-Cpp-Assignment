#include <bits/stdc++.h>

using namespace std;

//simple
int lootCase(int *arr, int size) {
    if(size == 0) {
        return 0;
    }
    if(size == 1) {
        return arr[0];
    }
    if(size == 2) {
        return max(arr[0], arr[1]);
    }
    int option1 = arr[0] + lootCase(arr + 2, size - 2);
    int option2 = arr[1] + lootCase(arr + 3, size - 3);

    return max(option1, option2);
}

int main() {
    int size;
    cin >> size;

    int *arr = new int[size];
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    int *memory = new int[size];
    for(int i = 0; i < size; i++) {
        memory[i] = -1;
    }
    cout << lootCase(arr, size);
    return 0;
}