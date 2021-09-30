#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    int *arr = new int[size];
    unordered_map<int, int> myMap;

    for(int i = 0; i < size; i++) {
        cin >> arr[i];
        myMap[arr[i]] += 1;
    }

    int k;
    cin >> k;
    // cout << "input done" << endl;

    unordered_map<int, int> :: iterator it = myMap.begin();
    if(k == 0) {
        int count = 0;
        while(it != myMap.end()) {
            if(it -> second == 1) {
                continue;
            }
            if(it -> second == 2) {
                count++;
                continue;
            }
            if(it -> second > 2) {
                int sum = 1;
                for(int i = 2; i < it -> second; i++) {
                    sum += i;
                }
                count += sum;
            }
            it++;
        }
        cout << count;
        return 0;
    }

    //4 
    //5 1 2 4
    //3
    it = myMap.begin();
    int count = 0;
    while(it != myMap.end()) {
        // cout << "in While" << " it -> first : " << it -> first << " it -> second : " << it -> second << endl;
        int first = it -> first;
        int diff = abs(k - first);
        // cout << "diff : " << diff << endl;
        if(myMap.count(diff) > 0) {
            if(myMap.at(diff) == 0) {
                it++;
                continue;
            }
            count++;
            myMap[diff]--;
            it -> second--;
        }
        it++;
    }
    cout << count;

    return 0;
}