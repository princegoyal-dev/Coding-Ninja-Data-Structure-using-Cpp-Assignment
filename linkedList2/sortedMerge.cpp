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

Node* mergeSorted(Node *head, Node *head2) {
    Node *newHead = NULL;
    Node *mainHead = newHead;
    while(head != NULL) {
        if(head2 == NULL) {
            break;
        }
        if(head -> data <= head2 -> data) {
            if(newHead == NULL) {
                newHead = head;
                mainHead = head;
            } else {
                newHead -> next = head;
                newHead = head;
            }
            head = head -> next;
        } else {
            if(newHead == NULL) {
                newHead = head2;
                mainHead = head2;
            } else {
                newHead -> next = head2;
                newHead = head2;
            }
            head2 = head2 -> next;
        }
    }
    if(head != NULL) {
        while(head != NULL) {
            if(newHead == NULL) {
                newHead = head;
                mainHead = head;
            } else {
                newHead -> next = head;
                newHead = head;
            }
            head = head -> next;
        }
    }
    if(head2 != NULL) {
        while(head2 != NULL) {
            if(newHead == NULL) {
                newHead = head2;
                mainHead = head2;
            } else {
                newHead -> next = head2;
                newHead = head2;
            }
            head2 = head2 -> next;
        }
    }
    return mainHead;
}

int main() {
    Node *head = takeInput();
    print(head);

    Node *head2 = takeInput();
    print(head2);

    Node *finalHead = mergeSorted(head, head2);
    print(finalHead);

    return 0;
}