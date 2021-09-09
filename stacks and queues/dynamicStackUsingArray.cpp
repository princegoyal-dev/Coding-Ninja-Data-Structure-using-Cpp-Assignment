#include <bits/stdc++.h>
using namespace std;
class Stack {
     int *data;
     int capacity;
     int nextIndex;

     public :
        Stack() {
            data = new int[10];
            capacity = 10;
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
                int *newData = new int[capacity * 2];
                for(int i = 0; i < capacity; i++) {
                    newData[i] = data[i];
                }
                capacity *= 2;
                delete data;
                data = newData;
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