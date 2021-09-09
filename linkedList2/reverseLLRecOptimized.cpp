#include <bits/stdc++.h>
#include "Node.cpp"

using namespace std;

Node* takeInput() {
    Node* head = NULL;
    Node* tail = NULL;

    int data;
    cin >> data;

    while(data != -1) {
        Node* newNode = new Node(data);
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

void print(Node* head) {
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
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

int main() {
    Node *head = takeInput();
    print(head);
    
    head = reverseLLRec(head);
    print(head);
    return 0;
}