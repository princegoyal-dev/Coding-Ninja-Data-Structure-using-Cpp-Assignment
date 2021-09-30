#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    int *arr = new int[size];

    priority_queue<int> pq;
    queue<int> q;
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
        pq.push(arr[i]);
        q.push(arr[i]);
    }

    int index;
    cin >> index;

    int time = 0;
    while(true) {
        // cout << "index : " << index << endl;
        if(q.front() == pq.top() && index == 0) {
            time++;
            // cout << "done" << endl;
            break;

        } else if(q.front() != pq.top() && index == 0) {
            index = size - 1;
            int element = q.front();
            q.pop();
            q.push(element);

        } else if(q.front() == pq.top()) {
            time++;
            q.pop();
            pq.pop();
            index--;

        } else {
            index--;
            int element = q.front();
            q.pop();
            q.push(element);
        }
    }
    cout << time;

    return 0;
}