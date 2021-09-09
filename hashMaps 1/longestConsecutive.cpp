#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    int *arr = new int[size];
    unordered_map<int, bool> myMap;

    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int start;
    int end;
    int length = 0;
    int maxLength = 0;
    int resultStart;
    int resultEnd;

    for(int i = 0; i < size; i++) {
        myMap[arr[i]] = false;
    }

    for(int i = 0; i < size; i++) {
        int currentElem = arr[i];
        if(myMap.at(currentElem) == true) {
            continue;
        }
        length = 1;
        myMap[currentElem] = true;
        start = currentElem;
        end = currentElem;

        int previous = currentElem + 1;

        while(true) {
            // cout << "first while" << endl;
            // cout << "previous : " << previous << endl;
            if(myMap.count(previous) > 0) {
                if(myMap.at(previous) == true) {
                    // cout << "element : " << previous << " already checked" << endl;
                    break;
                }
                myMap[previous] = true;
                end = previous;
                
            } else {
                // cout << "else break, element not found : " << previous << endl;
                break;
            }
            length++;
            previous += 1;
        }
        // cout << "length : " << length << endl;
        int next = arr[i] - 1;
        while(true) {
            // cout << "second while" << endl;
            // cout << "next : " << next << endl;
            if(myMap.count(next) > 0) {
                if(myMap.at(next) == true) {
                    // cout << "element : " << next << " already checked" << endl;
                    break;
                }
                myMap[next] = true;
                start = next;
            } else {
                // cout << "else break, element not found : " << next << endl;
                break;
            }
            length++;
            next -= 1;
        }
        // cout << "length : " << length << endl;
        if(maxLength == length) {
            for(int j = 0; j < size; j++) {
                if(start == arr[j]) {
                    resultStart = start;
                    resultEnd = end;
                    break;
                }
                if(resultStart == arr[j]) {
                    break;
                }
            }
        } else if(maxLength < length) {
            maxLength = length;
            resultStart = start;
            resultEnd = end;
        }
        length = 0;
        // cout << "maxLength : " << maxLength << " resultStart : " << resultStart << " resultEnd : " << resultEnd << endl;
        
    }
    // cout << "lenght : " << maxLength << " start : " << resultStart << " end : " << resultEnd;
    cout << resultStart << " " << resultEnd;
    return 0;
}
//13
//2 12 9 16 10 5 3 20 25 11 1 8 6