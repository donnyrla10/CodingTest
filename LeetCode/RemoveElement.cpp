#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int removeElement(vector<int> nums, int val) {
    nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
    return nums.size();
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cout << removeElement({3,2,2,3}, 3) << '\n';
    cout << removeElement({0,1,2,2,3,0,4,2}, 2) << '\n';
    return 0;
}
