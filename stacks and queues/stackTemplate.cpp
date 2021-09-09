#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Stack {
    T *data;
    int capacity;
    int nextIndex;

    public :
        Stack() {
            data = new T(4);
            capacity = 4;
            nextIndex = 0;
        }
        int size() {
            return nextIndex;
        }
        T top() {
            return data[nextIndex - 1];
        }
        bool isEmpty() {
            return nextIndex == 0;
        }
        void push(T value) {
            if(nextIndex == capacity) {
                T *newData = new T[capacity * 2];
                for(int i = 0; i < capacity; i++) {
                    newData[i] = data[i];
                }
                capacity *= 2;
            }
            data[nextIndex] = value;
            nextIndex++;
        }
        T pop() {
            if(isEmpty()) {
                cout << "Stack is Empty" << endl;
                return (T)0;
            } else {
                nextIndex--;
                return data[nextIndex];
            }
        }
};