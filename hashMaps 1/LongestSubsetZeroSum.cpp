#include <bits/stdc++.h>

using namespace std;

int findLongestSubsetSumZero(int *arr, int size) {
    unordered_map<int, int> sumIndexMap;
    int sum = 0;
    int longestLength = 0;
    int length = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
        if(sumIndexMap.count(sum) > 0) {
            length = i - sumIndexMap.at(sum);
            if(longestLength < length) {
                longestLength = length;
            }
        }
        sumIndexMap[sum] = i;
    }

    return longestLength;
}

int main() {
    int size;
    cin >> size;

    int *arr = new int[size];

    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int resultSize = findLongestSubsetSumZero(arr, size);

    cout << resultSize;

    return 0;
}