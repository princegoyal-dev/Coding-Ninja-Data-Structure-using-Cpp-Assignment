//output :
//0x1f17f0 5
//0x1f17f0 2038624
#include<bits/stdc++.h>

using namespace std;

int main() {
    int *p = new int(5);
    cout << p << " " << *p << endl;
    delete p;

    cout << p << " " << *p << endl;
    return 0;
}