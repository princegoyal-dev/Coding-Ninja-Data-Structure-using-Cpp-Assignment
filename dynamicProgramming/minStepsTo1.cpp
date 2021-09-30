#include <bits/stdc++.h>

using namespace std;

int minStepsTo1(int *arr, int num) {
    if(num <= 1) {
        return 0;
    }
    if(arr[num] != -1) {
        return arr[num];
    }
    int option1 = minStepsTo1(arr, num - 1);
    int option2 = INT_MAX;
    if(num % 2 == 0) {
        option2 = minStepsTo1(arr, num / 2);
    }
    int option3 = INT_MAX;
    if(num % 3 == 0) {
        option3 = minStepsTo1(arr, num / 3);
    }
    arr[num] = min(option1, min(option2, option3)) + 1;

    return arr[num];
}

int main() {
    int num;
    cin >> num;

    int *arr = new int[num + 1];
    for(int i = 0; i <= num; i++) {
        arr[i] = -1;
    }
    int result = minStepsTo1(arr, num);

    cout << result;

    return 0;
}