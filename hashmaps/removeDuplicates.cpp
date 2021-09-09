#include <bits/stdc++.h>

using namespace std;

int main() {
    string str = "my name is prince my is name goyal";
    stringstream ss(str);
    string temp;

    unordered_map<string, bool> ourMap;
    vector<string> myVec;

    while(getline(ss, temp, ' ')) {
        if(ourMap.count(temp) > 0) {
            continue;
        }
        ourMap[temp] = true;
        myVec.push_back(temp);
    }
    for(int i = 0; i < myVec.size() ; i++) {
        cout << myVec.at(i) << endl;
    }
}