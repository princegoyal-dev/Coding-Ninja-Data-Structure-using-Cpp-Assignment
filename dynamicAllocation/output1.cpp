//output : d
#include<bits/stdc++.h>

using namespace std;

void updateValue(int *p) {
    *p = 610 % 255;
}

int main() {
    char ch = 'A';
    updateValue((int*)&ch);
    cout << ch;
    return 0;
}