#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> nums = {3,3}; // 2 3 4
    int target = 6;
    int l = 0, r = nums.size()-1;
    vector<pair<int, int>> tmp;
    
    for(int i=0; i<nums.size(); i++) tmp.push_back({i, nums[i]});
    
    vector<int> answer;
    sort(tmp.begin(), tmp.end(), compare);
        
    while(r > l && tmp[r].second + tmp[l].second != target){
        if(tmp[l].second + tmp[r].second > target) r--;
        else                                       l++;
    }
    
    if(tmp[r].second + tmp[l].second == target){
        answer.push_back(tmp[l].first);
        answer.push_back(tmp[r].first);
    }
}
