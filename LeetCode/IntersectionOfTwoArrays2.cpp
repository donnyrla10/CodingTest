#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> intersect(vector<int> nums1, vector<int> nums2) {
    vector<int> ans;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    
    int i=0, j=0;
    while(nums1.size() > i && nums2.size() > j){
        if(nums1[i] == nums2[j]){
            ans.push_back(nums1[i++]);
            j++;
        }else if(nums1[i] > nums2[j]){
            j++;
        }else{
            i++;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> ans2 = intersect({9,1}, {9,9,1,5});
    for(auto i: ans2) cout << i << ' ';
    cout << '\n';
    return 0;
}
