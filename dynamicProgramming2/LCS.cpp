#include <bits/stdc++.h>

using namespace std;

//recursive
int lcs(string str1, string str2) {
    //if size of any string is zero return 0 as there is no common substring
    if(str1.size() == 0 || str2.size() == 0) {
        return 0;
    }
    //case 1 : if first character is same then recursive call for the next substring
    if(str1[0] == str2[0]) {
        return 1 + lcs(str1.substr(1), str2.substr(1));
    } else {
        //case 2.1 : discard first charcter from both strings
        int option1 = lcs(str1.substr(1), str2.substr(1));

        //case 2.2 : discard first character from second string
        int option2 = lcs(str1, str2.substr(1));

        //case 2.3 : discard first character from first string
        int option3 = lcs(str1.substr(1), str2);

        //return length of maximum common substring
        return max(option1, max(option2, option3));
    }
}

//memoisation
int lcsMemo(string str1, string str2, int **output) {
    //if size of any string is zero return 0 as there is no common substring
    if(str1.size() == 0 || str2.size() == 0) {
        return 0;
    }
    int m = str1.size();
    int n = str2.size();

    //if result already present in memoisation
    //here m refers to size left in string1 and n refers to size left in string2
    if(output[m - 1][n - 1] != -1) {
        return output[m - 1][n - 1];
    }

    //case 1 : if first character is same then recursive call for the next substring
    int result;
    if(str1[0] == str2[0]) {
        result = 1 + lcsMemo(str1.substr(1), str2.substr(1), output);
    } else {
        //case 2.1 : discard first charcter from both strings
        int option1 = lcsMemo(str1.substr(1), str2.substr(1), output);

        //case 2.2 : discard first character from second string
        int option2 = lcsMemo(str1, str2.substr(1), output);

        //case 2.3 : discard first character from first string
        int option3 = lcsMemo(str1.substr(1), str2, output);

        //return length of maximum common substring
        result = max(option1, max(option2, option3));
    }
    output[m - 1][n - 1] = result;

    return result;
}

//DP
int lcsDP(string str1, string str2) {
    //storing length of both string to avoid long code
    int m = str1.length();
    int n = str2.length();

    //creating 2d matrix of lenght increased by 1 on both sides 
    //otherwise at the time of iteration you need to do -1 each time you are doing calculations(in indices)
    int **output = new int*[m + 1];
    for(int i = 0; i <= m; i++) {
        output[i] = new int[n + 1];
    }
    
    //if lenght of any string is zero largest substring will be zero
    for(int i = 0; i <= m; i++) {
        output[i][0] = 0;
    }
    for(int i = 0; i <= n; i++) {
        output[0][i] = 0;
    }

    //filling the rest of cells
    //i and j are the length of string1 and string2 respectively
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            
            //checking if first character is same at each iteration
            //m - i denotes how many letter are left in the string1 ie. str1[m - i] is the first character at iteration1
            //and same with n - j for string2
            if(str1[m - i] == str2[n - j]) {
                output[i][j] = 1 + output[i - 1][j - 1];
            } else {
                //three cases : here i - 1 refers to taking string from second character (by discarding first character)
                int option1 = output[i - 1][j - 1];
                int option2 = output[i - 1][j];
                int option3 = output[i][j - 1];
                output[i][j] = max(option1, max(option2, option3));
            }
        }
    }
    return output[m][n];
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    int result = lcs(str1, str2);

    cout << "recursive : " << result << endl;

    //output array for memoisation
    //where i, j represents the length of the string
    int **output = new int*[str1.length()];
    for(int i = 0; i < str1.length(); i++) {
        output[i] = new int[str2.length()];
        for(int j = 0; j < str2.length(); j++) {
            output[i][j] = -1;
        }
    }

    cout << "memoisation : " << lcsMemo(str1, str2, output) << endl;

    cout << "DP : " << lcsDP(str1, str2);
    return 0;
}