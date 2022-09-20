#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> intersection(vector<int> nums1, vector<int> nums2) {
    vector<int> ans;
    
    //remove duplicated values
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    nums1.erase(unique(nums1.begin(), nums1.end()),nums1.end());
    nums2.erase(unique(nums2.begin(), nums2.end()),nums2.end());
    
    for(int i=0; i<nums1.size(); i++){
        for(int j=0; j<nums2.size(); j++){
            if(nums1[i] == nums2[j]) ans.push_back(nums1[i]);
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> ans = intersection({4,9,5}, {9,4,9,8,4});
    for(auto i: ans) cout << i << ' ';
    cout << '\n';
    return 0;
}
