#include <bits/stdc++.h>

using namespace std;

int call = 0;

void printSubSeq(int num, string output, string *arrDialpadComb) {
    if(num == 0) {
        cout << output << " ";
        return;
    }
    int lastDigit = num % 10;
    string keyComb = arrDialpadComb[lastDigit - 2];

    for(int i = 0; i < keyComb.length(); i++) {
        printSubSeq(num / 10, keyComb[i] + output, arrDialpadComb);
        
    }
    
}

int main() {
    
    int num = 234;
    string output = "";
    string arrDialpadComb[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    printSubSeq(num, output, arrDialpadComb);
    return 0;
}