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
Node* reverseLLRec(Node *head) {
    if(head == NULL || head -> next == NULL) {
        return head;
    }
    Node *nextLL = reverseLLRec(head -> next);

    Node *tail = head -> next;
    tail -> next = head;
    head -> next = NULL;
    return nextLL;
}
Node* incrementByOne(Node *head) {
    head = reverseLLRec(head);
    Node *tempHead = head;
    int carry = 1;
    while(tempHead != NULL) {
        int data = tempHead -> data + carry;
        
        if(data > 9) {
            data = data % 10;
            carry = 1;
            tempHead -> data = data;
        } else {
            tempHead -> data = data;
            break;
        }
        tempHead = tempHead -> next;
    }
    head = reverseLLRec(head);
    return head;
}

int main() {
    Node *head = takeInput();

    head = incrementByOne(head);

    print(head);

    return 0;
}