// #include <bits/stdc++.h>
#include "dynamicStackUsingArray.cpp"

// using namespace std;

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;

    cout << s.size() << endl;

    cout << boolalpha << s.isEmpty() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.size() << endl;
    cout << s.top() << endl;
}