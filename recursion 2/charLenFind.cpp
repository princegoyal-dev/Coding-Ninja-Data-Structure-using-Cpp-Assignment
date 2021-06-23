#include <bits/stdc++.h>

using namespace std;

int getCharArrLen(char *arr) {
    if(*arr == '\0') {
        return 0;
    }
    int smallLength = getCharArrLen(arr + 1);

    return smallLength + 1;
}

int main() {
    char arr[] = "abcdefgh";

    int resultLen = getCharArrLen(arr);

    cout << resultLen;
    return 0;
}