#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int searchInsert(vector<int> nums, int target) {
    auto it = find(nums.begin(), nums.end(), target);
    if(it != nums.end()) return distance(nums.begin(), it);
    return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << searchInsert({1,3,5,6}, 5) << '\n';
    return 0;
}
