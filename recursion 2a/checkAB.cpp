//Program to implement checkAB using recursion
/*
Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
    a. The string begins with an 'a'
    b. Each 'a' is followed by nothing or an 'a' or "bb"
    c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false.

Sample input : aaabbabb
Sample output : true
*/
#include <bits/stdc++.h>

using namespace std;

bool checkAB(string s, bool isFirstA) {
    if(s.length() == 0) {
        return true;
    }

    bool isNextTrue = false;
    bool nextCheckAB;

    if(s[0] == 'a') {
        if(s[1] == 'a' || (s.substr(1, 2)) == "bb" || s[1] == '\0') {
            isNextTrue = true;
        }
        if(s[1] == '\0') {
            return true;
        }
        nextCheckAB = checkAB(s.substr(1), isFirstA);
        
    } else if(s.substr(0, 2) == "bb") {
        if(s[2] == '\0' || s[2] == 'a') {
            isNextTrue = true;
        }
        if(s[2] == '\0') {
            return true;
        }
        nextCheckAB = checkAB(s.substr(2), isFirstA);
    } else {
        return false;
    }

    

    if(isFirstA && isNextTrue && nextCheckAB) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string s = "aaabbabb";
    bool result = false;
    
    bool isFirstA = false;
    if(s[0] == 'a') {
        isFirstA = true;
        result = checkAB(s, isFirstA);
    } 

    cout << boolalpha << result;

    return 0;
}