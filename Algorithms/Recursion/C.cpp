#include <iostream>
#include <vector>
using namespace std;

int mctFromLeafValues(vector<int>& arr) {
    int n = arr.size();
    int ans = 0;
    int mul = 0;
    
    for (int i = 0; i < n-1; i++){
        int index = 0;
        mul = arr[0] * arr[1];
        for (int j = i; j < arr.size()-1; j++){
            if (mul > arr[j] * arr[j+1]){
                mul = arr[j] * arr[j+1];
                index = j;
            }
        }
        for (int o = 0; o < arr.size(); o++){
          cout << "- " << arr[o] << " - " << ans << endl;
        }
        cout << endl;
        ans += mul;
        arr = vector<int>(arr.begin()+index+1, arr.end());// + vector<int>(2);
    }
    return ans;
}
int main(){
  vector<int> v = {5, 2, 3};
  cout << mctFromLeafValues(v) << endl;
}