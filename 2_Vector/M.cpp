#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	cin >> n;

	vector<int> vec;

	for (int i = 0; i < n; i++){
		vec.push_back(i);
	}

	// vec.pop_back();

	// for (int i : vec){
	// 	cout << i << " ";
	// }


	vec.push_back(12);

	cout << endl << vec.size() << endl;
	cout << vec.capacity() << endl;

	return 0;
}
