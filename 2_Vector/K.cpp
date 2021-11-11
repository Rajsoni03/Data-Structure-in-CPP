#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	cin >> n;

	vector<int> vec;

	for (int i : vec){
		cin >> k;
		i = k;
	}

	for (int i : vec){
		cout << i << " ";
	}

	return 0;
}
