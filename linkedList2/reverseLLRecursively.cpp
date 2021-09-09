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

Node* reverseLLRec(Node *mainHead) {
    Node *head = mainHead;
    if(head == NULL || head -> next == NULL) {
        return head;
    }
    Node *nextReversed = reverseLLRec(head -> next);
    head = nextReversed;
    while(nextReversed -> next != NULL) {
        nextReversed = nextReversed -> next;
    }
    nextReversed -> next = mainHead;
    nextReversed -> next -> next = NULL;
    return head;
}

int main() {
    Node *head = takeInput();
    print(head);

    Node *reverseHead = reverseLLRec(head);
    print(reverseHead);
    return 0;
}