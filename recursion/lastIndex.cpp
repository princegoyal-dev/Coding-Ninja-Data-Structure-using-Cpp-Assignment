//Program to find the last occurence of a given number in a given array of size n
//Sample input : 1, 2, 3, 4, 8, 5, 6, 7, 8, 1, 2, 3, 6, 0
//size = 14
//num = 6;
//Sample output : 12
#include<bits/stdc++.h>

using namespace std;

int findLastIndex(int *arr, int size, int num) {
    if(size == 0) {
        return -1;
    }
    int nextLastIndex = findLastIndex(arr, size - 1, num);
    
    if(arr[size - 1] == num) {
        return size - 1;
    }
    return nextLastIndex;
}

int main() {
    int size = 14;
    int num = 6;
    int arr[] = {1, 2, 3, 4, 8, 5, 6, 7, 8, 1, 2, 3, 6, 0};

    int resultLastIndex = findLastIndex(arr, size, num);

    cout << resultLastIndex << endl;
    return 0;
}