/*
Program to replace each occurence of x to y in a given string
input format:
    string character1 character2
Sample input : prince n e
Sample output : priece

Sample input 2 : mynameisprincegoyal i a
Sample output 2 : mynameasprancegoyal
*/
#include <bits/stdc++.h>

using namespace std;

string xReplaceY(string s, char ch1, char ch2) {
    if(s.length() == 0) {
        return "";
    }
    string nextResultString = xReplaceY(s.substr(1, s.length() - 1), ch1, ch2);

    if(s[0] == ch1) {
        return ch2 + nextResultString;
    } else {
        return s[0] + nextResultString;
    }

    
}

int main() {
    string s;
    char ch1, ch2;

    cin >> s >> ch1 >> ch2;

    string resultString = xReplaceY(s, ch1, ch2);

    cout << resultString;
    return 0;
}