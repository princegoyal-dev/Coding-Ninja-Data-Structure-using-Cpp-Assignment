//Program to remove consecutive duplicates in a given string
/*
Sample input : aaaaaa
Sample output : a

Sample input 2 : aabbbc
Sample output 2 : abc
*/
#include <bits/stdc++.h>

using namespace std;

string remConsDup(string s) {
    if(s.length() == 0) {
        return "";
    }
    
    string nextString = remConsDup(s.substr(1, s.length() - 1));

    if(s[0] == nextString[0]) {
        return nextString;
    } else {
        return s[0] + nextString;
    }
}

int main() {
    string s;
    cin >> s;

    string resultString = remConsDup(s);

    cout << resultString;
    return 0;
}