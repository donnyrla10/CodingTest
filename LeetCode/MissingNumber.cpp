#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int missingNumber(vector<int> nums) {
    int ans = 0;
    int n = nums.size(); //number 개수
    for(int i=0; i<=n; i++){
        if(find(nums.begin(), nums.end(), i) == nums.end()) return i;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << missingNumber({3,0,1}) << '\n';
    cout << missingNumber({0,1}) << '\n';
    return 0;
}
