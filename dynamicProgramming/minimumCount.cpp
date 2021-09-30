#include <bits/stdc++.h>

using namespace std;

int countMinimum(vector<int> &memory, int num) {
    int sqrtCheck = sqrt(num);
    if(sqrtCheck * sqrtCheck == num) {
        return 1;
    }
    if(num <= 3) {
        return num;
    }
    if(memory[num] != -1) {
        return memory[num];
    }
    int result = num;
    int squareRoot = (int) sqrt(num);
    for(int i = 1; i <= squareRoot; i++) {
        int square = i * i;
        if(square > num) {
            break;
        } else {
            int calc = 1 + countMinimum(memory, num - square);
            result = min(result, calc);
            memory[num] = result;
        }
    }

    return result;
}

int main() {
    int num;
    cin >> num;

    vector<int> memory(num + 1, -1);
    memory[0] = 0;
    memory[1] = 1;
    memory[2] = 2;
    memory[3] = 3;
    int result = countMinimum(memory, num);

    cout << result;
    return 0;
}