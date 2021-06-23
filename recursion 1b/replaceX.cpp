//Program to replace characted 'x' from a given string
//Sample input : xassxb
//Sample output : assb
#include <bits/stdc++.h>

using namespace std;

string replaceX(string s) {
    if(s.length() == 0) {
        return "";
    }
    string removedXSubStr = replaceX(s.substr(1, s.length() - 1));

    if(s[0] == 'x') {
        return removedXSubStr;
    } else {
        return s[0] + removedXSubStr;
    }
}

int main() {
    string s = "xassxb";

    string result = replaceX(s);

    cout << result;
    return 0;
}