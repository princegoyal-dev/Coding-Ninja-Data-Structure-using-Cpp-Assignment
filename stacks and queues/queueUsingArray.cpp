#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Queue {
    T *data;
    int QueueSize;
    int frontIndex;
    int nextIndex;
    int capacity;

    public :
        Queue() {
            data = new T(5);
            frontIndex = -1;
            nextIndex = 0;
            QueueSize = 0;
            capacity = 5;
        }

        int size() {
            return QueueSize;
        }

        bool isEmpty() {
            return QueueSize == 0;
        }

        T front() {
            if(isEmpty()) {
                cout << "Queue is empty" << endl;
                return 0;
            }
            return data[frontIndex];
        }

        void enqueue(T value) {
            if(QueueSize == capacity) {
                T *newData = new T (capacity * 2);
                int k = 0;
                for(int i = frontIndex; i < capacity; i++) {
                    newData[k] = data[i];
                    k++;
                }
                for(int j = 0 ; j < frontIndex; j++) {
                    newData[k] = data[j];
                    k++;
                }
                delete data;
                data = newData;
                frontIndex = 0;
                nextIndex = capacity;
                capacity = capacity * 2;
            }
            data[nextIndex] = value;
            if(frontIndex == -1) {
                frontIndex = 0;
            }
            QueueSize++;
            nextIndex = (nextIndex + 1) % capacity;
        }

        T dequeue() {
            if(isEmpty()) {
                cout << "Queue is empty" << endl;
                return 0;
            }
            T tempData = data[frontIndex];
            frontIndex = (frontIndex + 1) % capacity;
            QueueSize--;
            return tempData;
        }
};

int main() {
    Queue <int> q;

    cout << q.front() << endl;  //0
    cout << q.size() << endl;   //0

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << q.dequeue() << endl;    //10
    cout << q.dequeue() << endl;    //20

    cout << q.size() << endl;       //3
    cout << q.front() << endl;      //30

    q.enqueue(60);
    q.enqueue(70);

    cout << q.isEmpty() << endl;    //0
    cout << q.size() << endl;   //5

    cout << q.dequeue() << endl;    //30
    cout << q.dequeue() << endl;    //40
    cout << q.dequeue() << endl;    //50
    cout << q.dequeue() << endl;    //60
    cout << q.dequeue() << endl;    //70
    cout << q.dequeue() << endl;    //0


    return 0;
}