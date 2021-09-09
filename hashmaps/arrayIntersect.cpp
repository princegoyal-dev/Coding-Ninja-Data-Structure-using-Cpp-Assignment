#include <bits/stdc++.h>

using namespace std;

/*
5
1 2 3 4 5  
8
1 2 4 6 7 8 9 3
*/

int main() {
    unordered_map<int, bool> ourMap;
    int size1;
    cin >> size1;
    int *arr1 = new int[size1];

    for(int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    int size2;
    cin >> size2;
    int *arr2 = new int[size2];

    for(int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    for(int i = 0; i < size1; i++) {
        ourMap[arr1[i]] = true;
    }
    vector<int> myVec;

    for(int i = 0; i < size2; i++) {
        if(ourMap.count(arr2[i]) > 0) {
            myVec.push_back(arr2[i]);
        }
    }

    for(int i = 0; i < myVec.size(); i++) {
        cout << myVec.at(i) << " ";
    }

    return 0;
}