//output : 90.5 3
#include<bits/stdc++.h>

using namespace std;

int main() {
    float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    float *ptr1 = &arr[0];
    float *ptr2 = ptr1 + 3;
    cout << *ptr2 << " ";
    //subtracting the address like 4x - x ie 3x, x here is the memory location of first index
    cout << ptr2 - ptr1; 
    return 0;
}