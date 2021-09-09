#include <bits/stdc++.h>

using namespace std;

void returnStockSpan(int *arr, int *spanArr, int size) {
    stack <int> mainStack;

    spanArr[0] = 1;
    mainStack.push(0);
    for(int i = 1; i < size; i++) {
        if(arr[i] <= arr[mainStack.top()]) {
            spanArr[i] = 1;
            mainStack.push(i);
            continue;
        }
        while(arr[i] > arr[mainStack.top()]) {
            mainStack.pop();
            if(mainStack.empty()) {
                break;
            }
        }
        if(mainStack.empty()) {
            spanArr[i] = i + 1;
        } else {
            spanArr[i] = i - mainStack.top();
        }
        mainStack.push(i);
    }
}

int main() {
    int arr[] = {5, 3, 8, 7, 10, 7, 7, 12, 16};
    int size = sizeof(arr) / sizeof(arr[0]);

    int *spanArr = new int[size];

    returnStockSpan(arr, spanArr, size);

    for(int i = 0; i < size; i++) {
        cout << spanArr[i] << " ";
    }
    return 0;
}