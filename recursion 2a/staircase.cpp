/*
Program to implement staircase problem using recursion
    A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time.
    Implement a method to count how many possible ways the child can run up to the stairs.
    You need to return number of possible ways W.
Sample input : 4
Sample input : 7

Sample input : 30
Sample output : 53798080
*/

#include <bits/stdc++.h>

using namespace std;

int findWays(int stairs) {
    if(stairs <= 0) {
        return 1;
    }

    int waysFor1 = 0, waysFor2 = 0, waysFor3 = 0;
    if(stairs <= 1) {
        waysFor1 = findWays(stairs - 1);
    
    } else if(stairs <= 2) {
        waysFor1 = findWays(stairs - 1);
        waysFor2 = findWays(stairs - 2);

    } else {
        waysFor1 = findWays(stairs - 1);
        waysFor2 = findWays(stairs - 2);
        waysFor3 = findWays(stairs - 3);
    }


    return waysFor1 + waysFor2 + waysFor3;
}

int main() {
    int stairs = 30;

    int result = findWays(stairs);

    cout << result << endl;
    return 0;
}