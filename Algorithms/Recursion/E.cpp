// factorial of n
/*
fact(n) = n * (n-1) * (n-2) * ..... * 3 * 2 * 1
*/

#include <iostream>
using namespace std;

int fact(int n){
    if (n<=1) return 1;
    return n * fact(n-1);
}

int main(){
    cout << fact(4);
    return 0;
}