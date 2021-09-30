#include <bits/stdc++.h>

using namespace std;

class PriorityQueue {
    vector<int> pq;

    public :
        PriorityQueue() {

        }
        int getSize() {
            return pq.size();
        }
        bool isEmpty() {
            return pq.size() == 0;
        }
        int getMin() {
            if(isEmpty()) {
                return INT_MAX;
            }
            return pq[0];
        }

        //insertion code
        void insert(int value) {
            pq.push_back(value);
            int childIndex = pq.size() - 1;

            while(childIndex > 0) {
                int parentIndex = (childIndex - 1) / 2;
                if(pq[parentIndex] > pq[childIndex]) {
                    int temp = pq[parentIndex];
                    pq[parentIndex] = pq[childIndex];
                    pq[childIndex] = temp;
                } else break;
                childIndex = parentIndex;
            }
        }
        int removeMin() {
            if(isEmpty()) {
                return INT_MAX;
            }
            int ans = pq[0];
            pq[0] = pq[pq.size() - 1];
            pq.pop_back();

            //down-heapify
            int parentIndex = 0;
            int leftChildIndex = (2 * parentIndex) + 1;
            int rightChildIndex = (2 * parentIndex) + 2;
            while(leftChildIndex < pq.size()) {
                int minIndex = parentIndex;
                if(pq[minIndex] > pq[leftChildIndex]) {
                    minIndex = leftChildIndex;
                }
                if(rightChildIndex < pq.size() && pq[minIndex] > pq[rightChildIndex]) {
                    minIndex = rightChildIndex;
                }
                if(minIndex == parentIndex) {
                    break;
                }
                int temp = pq[minIndex];
                pq[minIndex] = pq[parentIndex];
                pq[parentIndex] = temp;

                parentIndex = minIndex;
                leftChildIndex = (2 * parentIndex) + 1;
                rightChildIndex = (2 * parentIndex) + 2;
            }
            return ans;
        }
};

int main() {
    PriorityQueue pq;
    cout << "size : " << pq.getSize() << endl;
    pq.insert(2);
    pq.insert(5);
    pq.insert(3);
    pq.insert(8);
    pq.insert(1);
    cout << "size : " << pq.getSize() << endl;
    cout << pq.removeMin() << endl;
    cout << pq.removeMin() << endl;
    cout << pq.getMin() << endl;
    cout << pq.getSize() << endl;

    return 0;
}