#include <bits/stdc++.h>

using namespace std;

//recursive
int calcEditDistance(string str1, string str2) {
    if(str1.size() == 0 || str2.size() == 0) {
        return max(str1.size(), str2.size());
    }
    if(str1[0] == str2[0]) {
        return calcEditDistance(str1.substr(1), str2.substr(1));
    } else {
        // inserting first char of str1 at start of str2
        int option1 = calcEditDistance(str1.substr(1), str2);

        // removing first char from str2
        int option2 = calcEditDistance(str1, str2.substr(1));

        // updating first char from str2
        int option3 = calcEditDistance(str1.substr(1), str2.substr(1));

        //taking minimum and adding 1(because 1 operation is done before doing all the above listed operations)
        return min(option1, min(option2, option3)) + 1;
    }
}

//memoisation
int calcEditDistanceMemo(string str1, string str2, int **output) {
    if(str1.size() == 0 || str2.size() == 0) {
        return max(str1.size(), str2.size());
    }

    int m = str1.length();
    int n = str2.length();
    if(output[m][n] != -1) {
        return output[m][n];
    }
    
    int result;
    if(str1[0] == str2[0]) {
        result = calcEditDistance(str1.substr(1), str2.substr(1));
    } else {
        // inserting first char of str1 at start of str2
        int option1 = calcEditDistance(str1.substr(1), str2);

        // removing first char from str2
        int option2 = calcEditDistance(str1, str2.substr(1));

        // updating first char from str2
        int option3 = calcEditDistance(str1.substr(1), str2.substr(1));

        //taking minimum and adding 1(because 1 operation is done before doing all the above listed operations)
        result = min(option1, min(option2, option3)) + 1;
    }
    output[m][n] = result;
    return result;
}

//DP
int calcEditDistanceDP(string str1, string str2) {
    int m = str1.size();
    int n = str2.size();

    int **output = new int*[m + 1];
    for(int i = 0; i <= m; i++) {
        output[i] = new int[n + 1];
    }

    for(int i = 0; i <= m; i++) {
        output[i][0] = i;
    }
    for(int i = 0; i <= n; i++) {
        output[0][i] = i;
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(str1[m - i] == str2[n - j]) {
                output[i][j] = output[i - 1][j - 1];
            } else {
                //insert
                int option1 = output[i - 1][j];
                
                //remove
                int option2 = output[i][j - 1];

                //update
                int option3 = output[i - 1][j - 1];

                output[i][j] = min(option1, min(option2, option3)) + 1;
            }
        }
    }
    return output[m][n];
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    int result = calcEditDistance(str1, str2);

    cout << "recursive : " << result << endl;

    int m = str1.length();
    int n = str2.length();
    int **output = new int*[m + 1];
    for(int i = 0; i <= m; i++) {
        output[i] = new int[n + 1];
        for(int j = 0; j <= n; j++) {
            output[i][j] = -1;
        }
    }

    cout << "memoisation : " << calcEditDistanceMemo(str1, str2, output) << endl;

    cout << "DP : " << calcEditDistanceDP(str1, str2);
    return 0;
}