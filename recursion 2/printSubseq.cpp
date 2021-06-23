#include <bits/stdc++.h>

using namespace std;

int getSubseq(string s, string *output) {
    if(s.empty()) {
        output[0] = "";
        return 1;
    }
    int nextSubseq = getSubseq(s.substr(1), output);
    for(int i = 0; i < nextSubseq; i++) {
        output[i + nextSubseq] = s[0] + output[i];
    }
        
    return nextSubseq * 2;
}

int main() {
    string s = "abc";
    int size = pow(2, s.length()) + 1;
    string *output = new string[size];

    int arrSize = getSubseq(s, output);
    for(int i = 0; i < arrSize; i++) {
        cout << output[i] << endl;
    }
    return 0;
}