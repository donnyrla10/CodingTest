#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> nums){
    int answer = 0;
    int canTake = nums.size()/2;
    sort(nums.begin(), nums.end());
    int p = nums[0];
    int cnt = 1;
    for(int i=1; i<nums.size(); i++){
        if(p != nums[i]) {
            cnt++;
            p = nums[i];
        }
    }
    answer = (canTake <= cnt) ? canTake : cnt;
    return answer;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cout << solution({3,1,2,3}) << '\n';        //2
//    cout << solution({3,3,3,2,2,4}) << '\n';    //3
//    cout << solution({3,3,3,2,2,2}) << '\n';    //2
    return 0;
}
