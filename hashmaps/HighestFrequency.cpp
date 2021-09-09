#include <bits/stdc++.h>

using namespace std;

int main() {
    int arr[] = {1, 2, 4, 5, 3, 4, 2, 1, 2, 1, 1, 2};
    map<int, int> ourMap;
    int size = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < size; i++) {
        ourMap[arr[i]]++;
    }
    map<int, int> :: iterator iter = ourMap.begin();
    int item;
    int frequency = 0;
    while(iter != ourMap.end()) {
        // cout << "iter -> first : " << iter -> first << " " << "iter -> second : " << iter -> second << endl;
        if(iter -> second > frequency) {
            frequency = iter -> second;
            item = iter -> first;
        }
        iter++;
    }
    // cout << item << " " << frequency << endl;
    iter = ourMap.begin();
    while(iter != ourMap.end()) {
        // cout << "iter -> first : " << iter -> first << " " << "iter -> second : " << iter -> second << endl;
        if(iter -> second == frequency) {
            item = iter -> first;
            break;
        }
        iter++;
    }

    cout << item << " " << frequency << endl;
    return 0;
}