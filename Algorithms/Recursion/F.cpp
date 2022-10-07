// digit sum
/*
digitSum(1234) = digitSum(123) + 4
               = digitSum(12) + 3 + 4
               = digitSum(1) + 2 + 3 + 4
               = digitSum() + 1 + 2 + 3 + 4
               = 0 + 1 + 2 + 3 + 4 = 10
*/

#include <iostream>
using namespace std;

int digitSum(int n){
	if (n<=0) return 0;
	return digitSum(n/10) + n%10;
}

int main(){
    cout << digitSum(1234);
    return 0;
}