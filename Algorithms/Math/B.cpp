// #include <iostream>
// using namespace std;

// int main(){
// 	int n = 5;
// 	int A[] = {3, 2, 5, 2, 2};
// 	int B[] = {1, 0, 1, 0, 0};


// 	// int n = 50;
// 	// int A[] = {35, 42, 19, 44, 4, 10, 2, 48, 6, 48, 38, 10, 42, 20, 47, 38, 48, 35, 35, 35, 15, 15, 16, 34, 25, 36, 33, 16, 43, 42, 33, 12, 46, 27, 45, 34, 12, 20, 33, 1, 5, 39, 25, 21, 44, 32, 39, 18, 43, 35};
// 	// int B[] = {1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0 ,0 ,0 ,0 ,1, 0, 0, 0, 0, 0 ,1 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1};

// 	int one = 0;
// 	int zero = 0;
// 	int o = 0;
// 	int z = 0;

// 	for (int i = 0; i < n; i++){
// 		if (B[i]){ one+=A[i];
// 			o++;
// 		}
// 		else {
// 			zero+=A[i];
// 			z++;
// 		}
// 	}

// 	cout << one%n << " " << zero%n << endl;
// 	cout << o << ' ' << z;


// 	return 0;
// }






#include <iostream>
using namespace std;

int main(){
	int n = 5;
	int A[] = {3, 2, 5, 2, 2};
	int B[] = {1, 0, 1, 0, 0};

	int i = 0;
	int count = 5;

	while(count-1){
		if (B[i] == 1){
			i = (i + A[i]+n-count) % n;
			B[i] = -1;
			i = (i + 1+n-count) % n;
		}
		else{
			i = (i + n - A[i]+n-count) % n;
			B[i] = -1;
			i = (i + n - 1+n-count) % n;
		}
		cout << A[i] << endl;
		count--;
	}

	for (int i = 0; i < n; i++){
		cout << A[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < n; i++){
		cout << B[i] << ' ';
	}

	return 0;
}