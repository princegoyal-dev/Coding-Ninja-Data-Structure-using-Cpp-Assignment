#include <bits/stdc++.h>
#include "Node.cpp"

using namespace std;

Node* takeInput() {
    Node *head = NULL;
    Node *tail = NULL;
    int data;
    cin >> data;
    while(data != -1) {
        Node *newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

int getLength(Node *head) {
    if(head == NULL) {
        return 0;
    }
    return 1 + getLength(head -> next);
}

int main() {
    Node *head = takeInput();
    
    cout << getLength(head);
    return 0;
}