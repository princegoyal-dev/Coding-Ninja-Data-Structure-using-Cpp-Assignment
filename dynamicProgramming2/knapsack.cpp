#include <bits/stdc++.h>

using namespace std;

//recursive solution
int knapsack(int *weight, int *value, int size, int totalWeight) {
    //if input size is 0 or if knapsack can hold 0 value then return 0
    if(size == 0 || totalWeight <= 0) {
        return 0;
    }

    //if first weight value is greater than max knapsack value than recursive call for the next weight value
    if(weight[0] > totalWeight) {
        return knapsack(weight + 1, value + 1, size - 1, totalWeight);
    }

    //case 1 : if we include first weight
    int option1 = knapsack(weight + 1, value + 1, size - 1, totalWeight - weight[0]) + value[0];
    
    //case 2 : if we didn't include first weight
    int option2 = knapsack(weight + 1, value + 1, size - 1, totalWeight);

    return max(option1, option2);
}

//memoisation
int knapsackMemo(int *weight, int *value, int size, int currIndex, int totalWeight, int **output) {
    if(size == 0 || totalWeight == 0) {
        return 0;
    }
    //we will be maintaining an output array 
    //which will store the 
    if(output[currIndex][totalWeight] != -1) {
        return output[currIndex][totalWeight];
    }
    int result;
    if(weight[0] > totalWeight) {
        result = knapsackMemo(weight + 1, value + 1, size - 1, currIndex + 1, totalWeight, output);
    } else {
        //included
        int option1 = knapsackMemo(weight + 1, value + 1, size - 1, currIndex + 1, totalWeight - weight[0], output) + value[0];

        //excluded
        int option2 = knapsackMemo(weight + 1, value + 1, size - 1, currIndex + 1, totalWeight, output);

        result = max(option1, option2);
    }
    output[currIndex][totalWeight] = result;
    
    return result;
}

//DP
int knapsackDP(int *weight, int *value, int size, int totalWeight) {
    int **output = new int*[size + 1];
    for(int i = 0; i <= size; i++) {
        output[i] = new int[totalWeight + 1];
        for(int j = 0; j <= totalWeight; j++) {
            output[i][j] = 0;
        }
    }
    for(int i = 1; i <= size; i++) {
        for(int j = 1; j <= totalWeight; j++) {
            if(weight[i - 1] > j) {
                output[i][j] = output[i - 1][j];
            } else {
                output[i][j] = max(output[i - 1][j], (value[i - 1] + output[i - 1][j - weight[i - 1]]));
            }
        }
    }
    return output[size][totalWeight];
}

int main() {
    int size;
    cin >> size;

    //weight array
    int *weight = new int[size];
    for(int i = 0; i < size; i++) {
        cin >> weight[i];
    }

    //value array
    int *value = new int[size];
    for(int i = 0; i < size; i++) {
        cin >> value[i];
    }

    //weight that knapsack can hold
    int totalWeight;
    cin >> totalWeight;

    int totalValue = knapsack(weight, value, size, totalWeight);

    cout << "recursive : " << totalValue << endl;

    int **output = new int*[size + 1];
    for(int i = 0; i <= size; i++) {
        output[i] = new int[totalWeight + 1];
        for(int j = 0; j <= totalWeight; j++) {
            output[i][j] = -1;
        }
    }

    cout << "memoisation : " << knapsackMemo(weight, value, size, 0, totalWeight, output) << endl;

    cout << "DP : " << knapsackDP(weight, value, size, totalWeight);

    return 0;
}