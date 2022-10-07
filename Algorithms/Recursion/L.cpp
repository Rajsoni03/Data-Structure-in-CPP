// Fibonacci Sequence 
/*
fib(n) = fib(n-1) + fib(n-2)
       = (fib(n-2) + fib(n-3)) + (fib(n-3) + fib(n-4))
          ...
       = .....  1 + 1

fib(4) = fib(3) + fib(2)
       = (fib(2) + fib(1)) + (fib(1) + fib(0))
       = (1 + 2) + (1 + 0)
*/

#include <iostream>
using namespace std;

int fib(int n){
  if (n <= 1) return n;
  return fib(n-1) + fib(n-2);

}

int main(){
    int n;
    cin >> n;
    cout << fib(n) ;
    return 0;
}