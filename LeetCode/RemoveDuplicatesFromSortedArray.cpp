#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> nums) {
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    return nums.size();
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cout << removeDuplicates({1,1,2}) << '\n';
    cout << removeDuplicates({0,0,1,1,1,2,2,3,3,4}) << '\n';
    return 0;
}
