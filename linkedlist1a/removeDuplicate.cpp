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

int getLength(Node *head) {
    if(head == NULL) {
        return 0;
    }
    return 1 + getLength(head -> next);
}

Node* removeDuplicates(Node *head) {
    Node *previousNode = head;
    Node *tempHead = head -> next;

    while(tempHead != NULL) {

        int data = previousNode -> data;
        int data2 = tempHead -> data;
        if(data2 == data) {
            Node *deletedNode = tempHead;
            previousNode -> next = tempHead -> next;
            tempHead = tempHead -> next;
            delete deletedNode;
            continue;
        }
        tempHead = tempHead -> next;
        previousNode = previousNode -> next;
    }
    return head;
}

int main() {
    Node *head = takeInput();
    print(head);

    head = removeDuplicates(head);
    print(head);

    return 0;
}