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
bool checkPalindrome(Node *mainHead) {
    Node *head = mainHead;
    int length = getLength(head);
    int midPoint = (length - 1) / 2;
    int i = 0;
    while(i <= midPoint) {
        head = head -> next;
        i++;
    }
    int *arr = new int[length - midPoint - 1];
    int k = 0;
    while(i < length) {
        arr[k] = head -> data;
        k++;
        head = head -> next;
        i++;
    }
    
    i = 0;
    for(int j = k - 1; j >= 0; j--) {
        if(mainHead -> data != arr[j]) {
            return false;
        } else {
            mainHead = mainHead -> next;
        }
    }
    return true;
}

int main() {
    Node *head = takeInput();

    bool result = checkPalindrome(head);
    cout << boolalpha << result;
}