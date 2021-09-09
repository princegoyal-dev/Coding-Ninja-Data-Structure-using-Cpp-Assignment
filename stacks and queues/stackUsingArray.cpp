#include <bits/stdc++.h>
using namespace std;
class Stack {
     int *data;
     int capacity;
     int nextIndex;

     public :
        Stack(int size) {
            data = new int[size];
            capacity = size;
            nextIndex = 0;
        }

        int top() {
            if(isEmpty()) {
                cout << " stack is empty" << endl;
                return INT_MIN;
            }
            return data[nextIndex - 1];
        }

        int size() {
            return nextIndex;
        }

        int isEmpty() {
            return nextIndex == 0;
        }

        void push(int value) {
            if(nextIndex == capacity) {
                cout << "Stack is full" << endl;
                return;
            }
            data[nextIndex] = value;
            nextIndex++;
        }

        int pop() {
            if(isEmpty()) {
                cout << "Stack is empty" << endl;
                return INT_MIN;
            }
            nextIndex--;
            return data[nextIndex];
        }
};