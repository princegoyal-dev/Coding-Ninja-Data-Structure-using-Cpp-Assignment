#include <bits/stdc++.h>

using namespace std;

bool coinTower(int coins, int option1, int option2) {
    if(coins == 0) {
        return false;
    }
    bool ans = false;
    if(coins >= option1 && !coinTower(coins - option1, option1, option2)) {
        ans =  true;
    }
    if(coins >= option2 && !coinTower(coins - option2, option1, option2)) {
        ans = true;
    }
    if(coins >= 1 && !coinTower(coins - 1, option1, option2)) {
        ans = true;
    }
    return ans;
}

int main() {
    int coins;
    cin >> coins;

    int option1;
    cin >> option1;

    int option2;
    cin >> option2;

    bool result = coinTower(coins, option1, option2);
    if(result) {
        cout << "Beerus";
    } else {
        cout << "Whis";
    }
    return 0;
}
/*
dp solution

//    Time Complexity : O(N)
//    Space Complexity : O(N)

//   where 'N' is the number of coins.
 
// Returns whether X is the winner or not.
int coinGameWinner(int n, int a, int b)
{

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        // Checking all three cases.
        if (!dp[i - 1])
        {
            dp[i] = 1;
        }

        if (i >= a && !dp[i - a])
        {
            dp[i] = 1;
        }

        if (i >= b && !dp[i - b])
        {
            dp[i] = 1;
        }
    }

    // Return the ans.
    return dp[n];
}
*/