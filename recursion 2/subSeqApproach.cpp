#include <bits/stdc++.h>

using namespace std;

void printSubSeq(string input, string output) {
    if(input.length() == 0) {
        cout << output << endl;
        return;
    }
    printSubSeq(input.substr(1), output);
    printSubSeq(input.substr(1), output + input[0]);
}

int main() {
    string s = "abc";
    string output = "";

    printSubSeq(s, output);

    return 0;
}