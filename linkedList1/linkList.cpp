#include <bits/stdc++.h>

using namespace std;

class Node {
    public :
        int data;
        Node *next;

        Node (int data) {
            this -> data = data;
            next = NULL;
        }
};

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

int getLengthLL(Node *head) {
    int length = 0;
    while(head != NULL) {
        head = head -> next;
        length++;
    }
    return length;
}
int getNode(Node *head, int position) {
    if(position < 0) {
        return -1;
    }
    if(position == 0) {
        return head -> data;
    }
    int i = 0;
    while(head != NULL && i < position) {
        head = head -> next;
        i++;
    }
    return head -> data;
}
void deleteNode(Node *head, int position) {
    int i = 0;
    while(head != NULL && i < position - 1) {
        head = head -> next;
        i++;
    }
    Node *deletedNode = head -> next;
    head -> next = head -> next -> next;
    delete deletedNode;
}

void print(Node *head) {
    Node *tempHead = head;
    while(tempHead != NULL) {
        cout << tempHead -> data << " ";
        tempHead = tempHead -> next;
    }
    cout << endl;
}

int main() {
    int testCases;
    cin >>testCases;

    while(testCases--) {
        Node *head = takeInput();
        print(head);

        // cout << getLengthLL(head) << endl;
        int position;
        cin >> position;

        // cout << getNode(head, position) << endl;

        deleteNode(head, position);
        print(head);
    }
    return 0;
}