//Program to convert given string to a number
//Sample input : "12321"
//Sample output : 12321
#include<bits/stdc++.h>

using namespace std;

int strToNum(string strNum) {
    if(strNum.length() == 0) {
        return 0;
    }

    int num = strToNum(strNum.substr(1, strNum.length() - 1));
    
    int firstDigit = strNum[0] - 48;
    int wholeNumFirstDigit =  firstDigit*pow(10, strNum.length() - 1);

    return wholeNumFirstDigit + num;
}

int main() {
    string strNum = "12321";

    int result = strToNum(strNum);
    
    cout << result;
    return 0;
}