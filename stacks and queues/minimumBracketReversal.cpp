#include <bits/stdc++.h>

using namespace std;

int minimumBracketReversal(string str) {
    stack <char> mainStack;
    int count = 0;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '{') {
            if(mainStack.empty()) {
                mainStack.push('{');

            } else if(mainStack.top() == '}') {
                mainStack.pop();
                count += 2;

            } else {
                mainStack.push('{');
            }
        } else if(str[i] == '}') {
            if(mainStack.empty()) {
                mainStack.push('}');

            } else if(mainStack.top() == '{') {
                mainStack.pop();
            } else {
                mainStack.push('}');
            }
        }
    }
    int size = mainStack.size();
    if(size % 2 == 1) {
        return -1;
    } else if(size % 2 == 0) {
        count += (size / 2);
        
    }
    return count;
}

int main() {
    string str = "}}{{{{}}{}}";
    
    cout << minimumBracketReversal(str) << endl;
    return 0;
}