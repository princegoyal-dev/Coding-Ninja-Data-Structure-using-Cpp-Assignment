//program to find the shortest subsequence from string 1 which is not present in string 2
#include <bits/stdc++.h>

using namespace std;

int findShortestLength(string str1, string str2, int len1, int len2) {
    //if length of string1 is 0 then there is no subsequence present
    if(len1 == 0) {
        return 100000;
    }

    //if length of string2 is 0 then smallest substring is any one character from string1
    if(len2 <= 0) {
        return 1;
    }

    //there will be two cases one is to include the first character from string1
    //and second is to not include the first character from string1
    
    //below code is for to include the first charcter from string1;
    //finding the index string1 0th character in string2
    int k;
    for(k = 0; k < len2; k++) {
        if(str2[k] == str1[0]) {
            break;
        }
    }
    //if there is not such character present in string2 return 1
    if(k == len2) {
        return 1;
    }
    return min(findShortestLength(str1.substr(1), str2, len1 - 1, len2), 1 + findShortestLength(str1.substr(1), str2.substr(k + 1), len1 - 1, len2 - k - 1));

}

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    int result = findShortestLength(str1, str2, str1.length(), str2.length());
    
    cout << result;
    return 0;
}