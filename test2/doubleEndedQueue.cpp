#include <bits/stdc++.h>

using namespace std;

class Dequeue {
    int *data;
    int capacity;
    int queueSize;
    int frontNextIndex;
    int frontIndex;
    int rearNextIndex;
    int rearIndex;

    public : 
        Dequeue(int capacity) {
            data = new int[capacity];
            this -> capacity = capacity;
            this -> capacity = capacity;
            queueSize = 0;
            frontNextIndex = 0;
            frontIndex = -1;
            rearNextIndex = 0;
            rearIndex = -1;
            
        }
        int size() {
            return queueSize;
        }

        void insertFront(int data) {
            if(queueSize == capacity) {
                return;
            }
            if(frontNextIndex >= rearNextIndex) {
                return;
            }
            this -> data[frontNextIndex] = data;
            frontNextIndex++;
            if(frontIndex == -1) {
                frontIndex = 0;
            }
            if(rearIndex = -1) {
                rearIndex = 
            }
        }


};

int main() {

}