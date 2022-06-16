#include <iostream>
#include <string>
using namespace std;

int func(string s1, string s2){
	bool flag = false;
	int index;
	for (int i = 0; i < s2.size(); i++){
		int j = i;
		index = 0;
		while(s1[j] == s2[index]){
			if (s2[j]!='\0') flag = true;
			j++;
			index++;
		}
		if (flag) break;
	}
	if (!flag) return -1;
	for (int i = 0; i < s2.size() - index; i++){
		if (s1[i] != s2[index+i]) {flag = false; break;};
	}
	return flag ? 1:-1;
}

int main(){
	string s1 = "sample";
	string s2 = "plesam";

	cout << func(s1, s2) << endl;

}
