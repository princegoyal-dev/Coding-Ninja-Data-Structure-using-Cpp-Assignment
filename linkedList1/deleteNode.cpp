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

void deleteNode(Node *head, int position) {
    if(head == NULL) {
        return;
    } else if(position == 0) {
        Node *deletedNode = head;
        head = head -> next;
        delete deletedNode;

    } else if(position == 1) {
        Node *deletedNode = head -> next;
        head -> next = head -> next -> next;
        delete deletedNode;

    } else {
        deleteNode(head -> next, position - 1);
    }
}

int main() {
    Node *head = takeInput();
    print(head);

    int position;
    cin >> position;

    deleteNode(head, position);
    print(head);

    return 0;
}