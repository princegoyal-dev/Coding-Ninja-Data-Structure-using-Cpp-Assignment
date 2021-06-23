//Program to place * in between two identical adjacent character in a given string
//Sample input : abbvjfkiirrfkk
//Sample output : ab*bvjfki*ir*rfk*k

#include<bits/stdc++.h>

using namespace std;

string identicalCharSep(string s) {
    if(s.length() == 0) {
        return "";
    }

    string smallStr = identicalCharSep(s.substr(1, s.length() - 1));

    string result;

    if(s[0] == smallStr[0]) {
        result = s[0];
        result.append("*");
        result.append(smallStr);

    } else {
        result = s[0];
        result.append(smallStr);
    }
    return result;
}

int main() {
    string s = "abbvjfkiirrfkk";

    string result = identicalCharSep(s);

    cout << result;
    return 0;
}