// program to find largest palindromic substring in a given string
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "abccbadabc";
    int resultLength = 1;
    for(int i = 0; i < s.length(); i++) {
        int j = i - 1;
        int k = i + 1;
        int subLength = 1;
        while(true) {
            if(j < 0 || k == s.length()) {
                break;
            } else if(s[j] != s[k]) {
                break;
            } else {
                j--;
                k++;
                subLength += 2;
                if(subLength > resultLength) {
                    resultLength = subLength;
                }
            }
        }
        int a = i;
        int b = i + 1;
        int subLength2 = 0;
        while(true) {
            if(a < 0 || b == s.length()) {
                break;
            } else if(s[a] != s[b]) {
                break;
            } else {
                a--;
                b++;
                subLength2 += 2;
                if(subLength2 > resultLength) {
                    resultLength = subLength2;
                }
            }
        }
    }

    cout << resultLength;
}