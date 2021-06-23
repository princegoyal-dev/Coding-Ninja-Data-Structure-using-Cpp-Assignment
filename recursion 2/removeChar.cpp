#include <bits/stdc++.h>

using namespace std;

void shiftLeft(char *arr) {
    int i;
    for(i = 0; arr[i] != '\0'; i++) {
        arr[i] = arr[i + 1];
    }
    arr[i] = '\0';
}

void removeChar(char *arr, char removable) {
    if(*arr == '\0') {
        return;
    }
    removeChar(arr + 1, removable);
    if(arr[0] == removable) {
        shiftLeft(arr);
    }
}

int main() {
    char arr[] = "abcxdexfgxh";
    char removable = 'x';

    removeChar(arr, removable);

    cout << arr;
    return 0;
}