#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node {
    public :
        T data;
        Node <T> *next;

        Node(T data) {
            this -> data = data;
            next = NULL;
        }
};
template <typename T>
class Queue {
    Node <T> *head;
    Node <T> *tail;
    int queueSize;

    public :
        Queue() {
            head = NULL;
            tail = NULL;
            queueSize = 0;
        }
        int size() {
            return queueSize;
        }
        T front() {
            if(isEmpty()) {
                cout << "Queue is Empty" << endl;
                return 0;
            }
            return head -> data;
        }
        bool isEmpty() {
            return queueSize == 0;
        }
        T dequeue() {
            if(isEmpty()) {
                cout << "Queue is empty" << endl;
                return 0;
            }
            T data = head -> data;
            Node <T> *tempNode = head;
            head = head -> next;
            delete tempNode;
            queueSize--;
            return data;
        }
        void enqueue(T value) {
            Node <T> *newNode = new Node <T> (value);
            if(head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail -> next = newNode;
                tail = newNode;
            }
            queueSize++;
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