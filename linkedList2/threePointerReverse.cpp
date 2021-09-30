#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node {
    public :
        T data;
        Node <T> *next;

        Node(T data) {
            this -> data = data;
            next = NULL;
        }
        ~Node() {
            delete next;
        }
};

Node<int>* reverseLL(Node<int> *head) {
    if(head == NULL) {
        return;
    }
    Node<int> *curr = head;
    Node<int> *prev = NULL;
    Node<int> *next = NULL;
    while(curr != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;

    }
    head = prev;
    return head;
}

int main() {
    return 0;
}