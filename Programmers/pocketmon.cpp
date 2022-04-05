#include <iostream>
#include <vector>
using namespace std;

//n마리의 폰켓몬 중에서 n/2마리를 가져가도 된다.
//예를 들어, [3,1,2,3] 네마리 폰켓몬이 있다면 여기서 두 마리를 고르는 방법 중에
//첫번째 3, 네번째 3을 고르면 한 종류의 폰켓몬만 가질 수 있다. 이를 제외하면 2종류의 폰켓몬을 가질 수 있다.
//최대한 다양한 종류의 폰켓몬을 가지고 싶다. 이때, 가질 수 있는 가장 많은 종류의 폰켓몬 종류를 리턴하라

int solution(vector<int> nums){
    int answer = 0;
    vector<int> mon; //종
    int cnt = 0;
    int canTake = nums.size()/2;
    for(int i=0; i<nums.size(); i++){
        auto it = find(mon.begin(), mon.end(), nums[i]);
        if(it == mon.end()) { //해당 값이 mon에 없다면
            mon.push_back(nums[i]);
            cnt++;
        }
    }
    answer = canTake < cnt ? canTake : cnt;
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << solution({3,1,2,3}) << '\n';
//    cout << solution({3,3,3,2,2,4}) << '\n';
//    cout << solution({3,3,3,2,2,2}) << '\n';
    return 0;
}
