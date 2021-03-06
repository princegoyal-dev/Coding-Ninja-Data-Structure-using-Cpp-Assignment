// credit : https://github.com/bhumikamudgal
#include <iostream>
using namespace std;

void printSubsetsOfArray(int input[], int size, int output[], int m) {     
    int newoutput[m+1];
    
    if(size==0) {
        for(int i=0;i<m;i++) {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }
    int k=0;
    printSubsetsOfArray(input+1,size-1,output,m);
    for(int i=0;i<m;i++) {
        newoutput[k++] = output[i];
    }
    newoutput[k] = input[0];
    printSubsetsOfArray(input+1,size-1,newoutput,m+1);
}

void printSubsetsOfArray(int input[], int size) {
    int output[1000];
    
    return printSubsetsOfArray(input,size,output,0);
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  printSubsetsOfArray(input, length);
}