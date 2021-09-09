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
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}

int getMidPoint(Node *head) {
    Node *tempHead = head;
    int midPoint = 0;
    while(tempHead -> next != NULL) {
        if(tempHead == NULL) {
            break;
        }
        if(tempHead -> next -> next == NULL) {
            break;
        }
        tempHead = tempHead -> next -> next;
        midPoint++;
    }
    return midPoint;
}

int main() {
    Node *head = takeInput();
    print(head);

    int midPoint = getMidPoint(head);
    cout << midPoint;
    return 0;
}