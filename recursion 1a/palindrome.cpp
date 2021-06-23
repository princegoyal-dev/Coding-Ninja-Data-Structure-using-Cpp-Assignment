//Program to find whether the given string is palindrome or not
//Sample input 1 : anbabna
//Sample output 2 : true
#include<bits/stdc++.h>

using namespace std;

bool checkPalindrome(string s) {
    int result;
    if(s.length() == 1 || s.length() == 0) {
        return true;
    }
    if(s[0] != s[s.length() - 1]) {
        return false;
    }

    bool checkSmallString = checkPalindrome(s.substr(1, s.length() - 2));

    return checkSmallString;
}

int main() {
    string s = "anbabna";

    bool result = checkPalindrome(s);

    cout << boolalpha << result << endl;
    return 0;
}