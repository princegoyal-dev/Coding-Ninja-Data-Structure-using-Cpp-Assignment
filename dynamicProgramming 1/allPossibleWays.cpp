// int allWays2(int num, int pow, int curr_num = 1, int curr_sum = 0) {
//     int result = 0;
//     int powerCalc = pow(curr_num, pow);
//     while(powerCalc + curr_sum < num) {
//         result += allWays2(num, pow, curr_num + 1, curr_sum + powerCalc);
//         curr_num++;
//         powerCalc = pow(curr_num, pow);
//     }
//     if(powerCalc + curr_sum == num) {
//         ++result;
//     }
//     return result;
// }

#include <iostream>
using namespace std;

int power(int num, unsigned int n) 
{ 
    if (n == 0) 
        return 1; 
    else if (n%2 == 0) 
        return power(num, n/2)*power(num, n/2); 
    else
        return num*power(num, n/2)*power(num, n/2);
}

int check(int x,int n,int curr_num,int curr_sum){
    int res=0;
    int p = power(curr_num,n);
    while(p+curr_sum<x){
        res += check(x,n,curr_num+1,curr_sum+p);
        curr_num++;
        p=power(curr_num,n);
    }
    if(p+curr_sum==x)
        res++;
    return res;
}

int allWays(int x, int n) {
    return check(x,n,1,0);
}

int main()
{
    int x, n;
    cin >> x >> n;
    cout << allWays(x, n);
    return 0;
}