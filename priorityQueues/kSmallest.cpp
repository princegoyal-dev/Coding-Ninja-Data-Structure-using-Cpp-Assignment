#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    int *arr = new int[size];
    
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    priority_queue<int> pq;
    unordered_map<int, bool> isPresent;

    for(int i = 0; i < k; i++) {
        pq.push(arr[i]);
        isPresent[arr[i]] = true;
    }

    for(int i = k; i < size; i++) {
        if(arr[i] < pq.top() &&  !(isPresent.count(arr[i]) > 0)) {
            pq.pop();
            pq.push(arr[i]);
            isPresent[arr[i]] = true;
        }
    }
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}