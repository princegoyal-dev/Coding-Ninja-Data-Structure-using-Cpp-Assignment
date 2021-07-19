#include <bits/stdc++.h>

using namespace std;

int fact(int num) {
    if(num == 1) {
        return 1;
    }
    return num * (num - 1);
}

int returnPermutations(string s, string *arr, int size) {
    if(s == "") {
        return 1;
    }
    int nextSize = returnPermutations(s.substr(1), arr, size - 1);
    string *tempArr = new string[size];
    int k = 0;
    for(int i = 0; i < nextSize; i++) {
        for(int j = 0; j < arr[0].length(); j++) {
            string temp = arr[i];
            
        }
    }
    
}

int main() {

    string s;
    cin >> s;

    int size = fact(s.length());

    string *arr = new string[size];

    returnPermutations(s, arr, size);



    return 0;
}