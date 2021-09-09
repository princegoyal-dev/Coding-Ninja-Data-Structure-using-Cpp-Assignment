#include <bits/stdc++.h>

using namespace std;

void reverseStack(stack <int> &s) {
    if(s.empty()) {
        return;
    }
    int data = s.top();
    s.pop();
    reverseStack(s);

    stack <int> tempStack;

    while(!s.empty()) {
        tempStack.push(s.top());
        s.pop();
    }

    tempStack.push(data);

    while(!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    stack <int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << s.top() << endl;

    reverseStack(s);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();

    return 0;
}