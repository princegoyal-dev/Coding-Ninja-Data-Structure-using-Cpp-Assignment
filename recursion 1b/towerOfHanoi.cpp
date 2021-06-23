//Program to implement tower of hanoi 
//Sample input : 5
/*Sample output :
Moving Disc From A to C
Moving Disc From A to B
Moving Disc From C to B
Moving Disc From A to C
Moving Disc From B to A
Moving Disc From B to C
Moving Disc From A to C
*/
#include<bits/stdc++.h>

using namespace std;
void towerOfHanoi(int noOfDiscs, char poleA, char poleB, char poleC) {
    if(noOfDiscs == 0) {
        return;
    }
    towerOfHanoi(noOfDiscs - 1, poleA, poleC, poleB);
    cout << "Moving Disc From " << poleA << " to " << poleC << endl;
    towerOfHanoi(noOfDiscs - 1, poleB, poleA, poleC);
}

int main() {
    int noOfDiscs = 3;
    char poleA = 'A', poleB = 'B', poleC = 'C';

    towerOfHanoi(noOfDiscs, poleA, poleB, poleC);

    return 0;
}