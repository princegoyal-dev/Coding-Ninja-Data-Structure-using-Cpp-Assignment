#include <bits/stdc++.h>

using namespace std;

bool checkString(string s, string t) {
    int *arr = new int[26];
    for(int i = 0; i < s.size(); i++) {
        arr[s[i] - 97] = 1;
    }
    for(int i = 0; i < t.size(); i++) {
        if(arr[t[i] - 97] == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    bool result = checkString(s, t);

    cout << boolalpha << result;
    return 0;
}