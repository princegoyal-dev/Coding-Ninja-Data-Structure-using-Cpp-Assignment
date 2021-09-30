#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    int *arr = new int[size];
    //12 7 5 9 4

    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    int k;
    cin >> k;

    priority_queue<int> pq;
    
    for(int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    int j = 0;
    for(int i = k; i < size; i++) {
        arr[j++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    while(pq.size() != 0) {
        arr[j++] = pq.top();
        pq.pop();
    }

    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}