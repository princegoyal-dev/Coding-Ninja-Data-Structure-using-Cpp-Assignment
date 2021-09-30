#include <bits/stdc++.h>

using namespace std;

int staircaseCount(vector<int> &memory, int stairs) {
    if(stairs <= 1) {
        return 1;
    }
    if(memory[stairs] != -1) {
        return memory[stairs];
    }
    int option1 = 0;
    if(stairs >= 1)
        option1 = staircaseCount(memory, stairs - 1);
    int option2 = 0;
    if(stairs >=2)
        option2 = staircaseCount(memory, stairs - 2);
    int option3 = 0;
    if(stairs >= 3)
        option3 = staircaseCount(memory, stairs - 3);

    memory[stairs] = option1 + option2 + option3;

    return memory[stairs];
}

int main() {
    int stairs;
    cin >> stairs;

    vector<int> memory(stairs + 1, -1);

    int countWays = staircaseCount(memory, stairs);
    cout << countWays;

    return 0;
}