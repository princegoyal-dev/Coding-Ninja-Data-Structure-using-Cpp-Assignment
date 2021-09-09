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

void print(Node *head) {
    Node *tempHead = head;
    while(tempHead != NULL) {
        cout << tempHead -> data << " ";
        tempHead = tempHead -> next;
    }
    cout << endl;
}

void insertNode(Node *head, int position, int data) {
    if(head == NULL) {
        return;
    } else if(head -> next == NULL) {
        Node *newNode = new Node(data);
        head -> next = newNode;
        newNode -> next = NULL;
        return;
    } else if(position == 1) {
        Node *nextRef = head -> next;
        Node *newNode = new Node(data);
        head -> next = newNode;
        newNode -> next = nextRef;
        return;
    } else {
        insertNode(head -> next, position - 1, data);
    }
    
}

int main() {
    Node *head = takeInput();
    print(head);

    int position;
    cin >> position;

    int data;
    cin >> data;

    insertNode(head, position, data);

    print(head);
    return 0;
}