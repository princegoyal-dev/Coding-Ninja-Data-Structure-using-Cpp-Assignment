#include <bits/stdc++.h>
#include "stackTemplate.cpp"

using namespace std;

int main() {
    Stack <int> s;

    cout << boolalpha << s.isEmpty() << endl;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.size() << endl;
    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.size() << endl;
    cout << s.top() << endl;

    cout << boolalpha << s.isEmpty() << endl;
    
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    Stack <char> s2;

    cout << boolalpha << s2.isEmpty() << endl;

    s2.push('a');
    s2.push('b');
    s2.push('c');
    s2.push('d');
    s2.push('e');

    cout << s2.size() << endl;
    cout << s2.top() << endl;

    cout << s2.pop() << endl;
    cout << s2.pop() << endl;

    cout << s2.size() << endl;
    cout << s2.top() << endl;

    cout << boolalpha << s2.isEmpty() << endl;
    
    cout << s2.pop() << endl;
    cout << s2.pop() << endl;
    cout << s2.pop() << endl;
    cout << s2.pop() << endl;
    return 0;
}