//Program to imlement the sequential combination of a dialpad with their alphabets respectively using recursion
//Sample input 1 : 23
/* Sample output :
    ad
    ae
    af
    bd
    be
    bf
    cd
    ce
    cf
*/
#include <bits/stdc++.h>

using namespace std;

int getCombination(int num, string *output, string *keyComb) {
    if(num <= 0) {
        return 1;
    }

    // cout << "num : " << num << endl;

    int nextNum = num / 10;
    // cout << "nextNum : " << nextNum << endl;

    int nextSize = getCombination(nextNum, output, keyComb);
    // cout << "nextSize : " << nextSize << endl;

    // cout << "num : " << num << endl;

    int lastDigit = num % 10;
    // cout << "lastDigit : " << lastDigit << endl;

    int size  = 0;
    
    string specificKeyComb = keyComb[lastDigit];
    // cout << "specifickeyComb : " << specificKeyComb << endl;

    for(int i = 0; specificKeyComb[i] != '\0'; i++) {
        size++;
    }
    // cout << "sizeOfspecificKeyComb : " << size << endl;

    for(int i = 0; i < nextSize; i++) {
        for(int j = 0; j < size; j++) {
            // cout << specificKeyComb[j] << endl;
            output[j + nextSize + (size * i)] = output[i] + specificKeyComb[j];
        }
    }
    // cout << "nextSize * size : " << nextSize * size << endl;
    return (nextSize * (size + 1));
}

int main() {
    int num = 23;
    
    string keyComb[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    string *output = new string[1000000];

    int outputSize = getCombination(num, output, keyComb);

    // cout << "outputSize : " << outputSize << endl;

    int size = 1;

    for(int i = 0; num != 0; i++) {
        size *= keyComb[num % 10].size();
        num /= 10;
    }
    // cout << "size : " << size << endl;

    for(int i = outputSize - size; i < outputSize; i++) {
        cout << output[i] << endl;
    }
    return 0;
}