#include <bits/stdc++.h>

using namespace std;

bool check(string str) {
    stack <char> s;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '{' || str[i] == '(' || str[i] == '[') {
            s.push(str[i]);
            
        } else if(str[i] == '}' || str[i] == ')' || str[i] == ']') {
            char stackTop = s.top();
            s.pop();

            if(str[i] == ')' && stackTop == '(') {
                continue;

            } else if(str[i] == '}' && stackTop == '{') {
                continue;

            }else if(str[i] == ']' && stackTop == '[') {
                continue;

            } else {
                return false;
            }
        }
    }
    if(s.empty()) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string str = "{a + (b - c) * d}";
    string str2 = "{a + (b - c} * d)";

    cout << check(str) << endl;
    cout << check(str2) << endl;
    return 0;
}