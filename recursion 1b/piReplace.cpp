//Program to replace pi with 3.14 in a given string 
//Sample input : pifpip
//Sample output : 3.14f3.14p
#include<bits/stdc++.h>

using namespace std;

string replacePi(string s) {
    if(s.length() == 0) {
        return "";
    }
    string temp = "";
    string subStr;
    if(s.substr(0,2) == "pi") {
        temp = "3.14";
        subStr = replacePi(s.substr(2, s.length()-2));
    } else {
        temp = s[0];
        subStr = replacePi(s.substr(1, s.length()-1));
    }
    
    return temp + subStr;
}

int main() {
    string s = "pifpip";

    string result = replacePi(s);

    cout << result;
    return 0;
}