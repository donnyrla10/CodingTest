#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int singleNumber(vector<int> nums) {
    sort(nums.begin(), nums.end());
    for(int i=1; i<nums.size(); i+=2){
        if(nums[i-1] != nums[i]) return nums[i-1];
    }
    return nums[nums.size()-1];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << singleNumber({2,2,1}) << '\n';
    cout << singleNumber({4,1,2,1,2}) << '\n';
    cout << singleNumber({1}) << '\n';
    return 0;
}
