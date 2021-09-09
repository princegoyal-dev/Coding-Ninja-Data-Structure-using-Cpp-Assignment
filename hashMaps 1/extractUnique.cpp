#include <bits/stdc++.h>

using namespace std;

string extractUnique(string str) {
    if(str == "") {
        return "";
    }
    unordered_map<char, bool> charCheck;
    string result = "";

    for(int i = 0; i < str.length(); i++) {
        if(charCheck.count(str[i]) > 0) {
            continue;
        } else {
            charCheck[str[i]] = true;
        }
        result += str[i];
    }
    return result;
}

int main() {
    string str = "aaaaaabbbbcccccddddeeeeefffffggggaaaahhhcccddd";
    // cin >> str;

    string result = extractUnique(str);

    cout << result;

    return 0;
}