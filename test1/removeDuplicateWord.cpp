#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    s = s + " ";
    vector <string> v;
    string delimiter = " ", token;
    size_t pos;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        v.push_back(token);
        // std::cout << token << std::endl;
        s.erase(0, pos + delimiter.length());
    }
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            if(j == i) {
                continue;
            }
            if(v[i] == v[j]) {
                v.erase(v.begin() + j);
            }
        }
    }
    string finalString = "";
    for(int i = 0; i < v.size(); i++) {
        finalString += v[i] + " ";
    }
    cout << finalString;
    return 0;
}