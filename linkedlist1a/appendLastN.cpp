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

Node* appendLastN(Node *head, int n) {
    if(n >= getLength(head)) {
        return head;
    }
    Node *startIndex = head;
    Node *endIndex = head;
    int i = 0;
    while(endIndex -> next != NULL) {
        endIndex = endIndex -> next;
        if(i >= n) {
            startIndex = startIndex -> next;
        }
        i++;
    }
    Node *tempHead = head;
    head = startIndex -> next;
    endIndex -> next = tempHead;
    startIndex -> next = NULL;
    return head;
}
int main() {
    Node *head = takeInput();
    print(head);

    int n;
    cin >> n;

    head = appendLastN(head, n);
    print(head);
    return 0;
}