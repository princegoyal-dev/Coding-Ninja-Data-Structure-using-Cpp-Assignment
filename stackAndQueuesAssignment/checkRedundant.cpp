#include <bits/stdc++.h>

using namespace std;

bool checkRedundant(string str) {
    if(str == "") {
        return true;
    }
    stack <char> mainStack;
    
    int count = 0;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ')') {
            char topCh = mainStack.top();
            while(topCh != '(') {
                mainStack.pop();
                count++;
                topCh = mainStack.top();
            }
            if(count > 0) {
                count = 0;
                continue;
            } else {
                return true;
            }
        } else {
            mainStack.push(str[i]);
        }
    }
    return false;
}

int main() {
    string str = "(a+b)+c";

    bool result = checkRedundant(str);

    cout << boolalpha << result;
    return 0;
}