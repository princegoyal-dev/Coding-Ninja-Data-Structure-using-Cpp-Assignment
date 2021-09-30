#include <bits/stdc++.h>

using namespace std;

int fibonacci(int index) {
    if(index == 0 || index == 1) {
        return index;
    }
    return fibonacci(index - 1) + fibonacci(index - 2);
}


//memoisation approach
unsigned long long fibonacci_2Helper(unsigned long long *arr, int index) {
    if(index == 0 || index == 1) {
        return index;
    }
    if(arr[index] != -1) {
        return arr[index];
    }
    arr[index] = fibonacci_2Helper(arr, index - 1) + fibonacci_2Helper(arr, index - 2);
    
    return arr[index];
}
unsigned long long fibonacci_2(int index) {
    unsigned long long *arr = new unsigned long long[index + 1];
    for(int i = 0; i < index + 1; i++) {
        arr[i] = -1;
    }
    unsigned long long result = fibonacci_2Helper(arr, index);
    return result;
}
//end

//dp approach
int fibonacciDp(int index) {
    int *ans = new int[index + 1];
    ans[0] = 0;
    ans[1] = 1;
    for(int i = 2; i <= index; i++) {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    return ans[index];
}

int main() {
    int index;
    cin >> index;

    cout << fibonacci_2(index);
    cout << "\nfirst done" << endl;
    cout << fibonacci(index);

    return 0;
}