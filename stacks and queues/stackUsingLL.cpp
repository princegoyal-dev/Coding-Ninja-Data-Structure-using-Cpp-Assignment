#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node {
    public :
        T data;
        Node *next;

        Node(T data) {
            this -> data = data;
            next = NULL;
        }
};

template <typename T>
class Stack {
    Node <T> *head;
    int stackSize;

    public :
        Stack() {
            stackSize = 0;
        }

        int size() {
            return stackSize;
        }

        bool isEmpty() {
            return stackSize == 0;
        }

        void push(T data) {
            Node <T> *newNode = new Node <int> (data);
            newNode -> next = head;
            head = newNode;
            stackSize++;
        }

        T top() {
            return head -> data;
        }

        T pop() {
            if(isEmpty()) {
                cout << "Stack is empty" << endl;
                return 0;
            }
            T data = head -> data;
            Node <T> *deletedNode = head;
            head = head -> next;
            delete deletedNode;
            stackSize--;
            return data;
        }
};

int main() {
    Stack <int> s;
    cout << s.pop() << endl;    //Stack is empty 0

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << endl;    //30
    s.push(40);
    cout << s.isEmpty() << endl; // 0
    s.push(50);
    s.push(60);

    cout << s.pop() << endl; //60
    cout << s.pop() << endl; //50

    cout << s.size() << endl; //4
    return 0;
}