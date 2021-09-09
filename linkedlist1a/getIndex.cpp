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

void print (Node *head) {
    Node *tempHead = head;
    while(tempHead != NULL) {
        cout << tempHead -> data << " ";
        tempHead = tempHead -> next;
    }
    cout << endl;
}

int getIndex(Node *head, int data) {
    int i = 0;
    while(head != NULL) {
        if(head -> data == data) {
            break;
        }
        i++;
        head = head -> next;
    }
    return i;
}

int main() {
    Node *head = takeInput();
    print(head);

    int data;
    cin >> data;

    int index = getIndex(head, data);
    cout << index;

    return 0;
}