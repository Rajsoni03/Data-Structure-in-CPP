// sum of numbers from 1 to n || n to 1
/*
sum = n + (n-1) + (n-2) + .....  + 3 + 2 + 1
or
sum = 1 + 2 + 3 + ..... + (n-2) + (n-1) + n
*/

#include <iostream>
using namespace std;

int sumOf(int n){
    if (n<=0) return 0;
    return sumOf(n-1) + n;
    // return n + sumOf(n-1);
}

int main(){
    cout << sumOf(10);
    return 0;
}