#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void merge(vector<int> nums1, int m, vector<int> nums2, int n) {
    for(int i=0; i<n; i++) nums1[m+i] = nums2[i];
    sort(nums1.begin(), nums1.end());
    for(auto i:nums1) cout << i << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    merge({0}, 0, {1}, 1);
    return 0;
}
