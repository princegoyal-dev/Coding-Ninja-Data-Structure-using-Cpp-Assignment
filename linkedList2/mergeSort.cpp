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

int getLength(Node* head) {
    if(head == NULL) {
        return 0;
    }
    return getLength(head -> next) + 1;
}

void frontBackSplit(Node *head, Node *&a, Node *&b) {
    Node *slow = head;
    Node *fast = head -> next;
    while(fast != NULL) {
        fast = fast -> next;
        if(fast != NULL) {
            slow = slow -> next;
            fast = fast -> next;
        }
    }
    a = head;
    b = slow -> next;
    slow -> next = NULL;
}

Node* mergeSorted(Node* a, Node* b)
{
    Node* result = NULL;
 
    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    /* Pick either a or b, and recur */
    if (a->data <= b->data) {
        result = a;
        result->next = mergeSorted(a->next, b);
    }
    else {
        result = b;
        result->next = mergeSorted(a, b->next);
    }
    return (result);
}

void mergeSort(Node* &mainHead) {
    Node *head = mainHead;
    Node *a, *b;
    if(head == NULL || head -> next == NULL) {
        return;
    }
    frontBackSplit(head, a, b);

    mergeSort(a);
    mergeSort(b);

    mainHead = mergeSorted(a, b);
}

int main() {
    Node *head = takeInput();
    print(head);
    
    mergeSort(head);
    print(head);

    return 0;
}