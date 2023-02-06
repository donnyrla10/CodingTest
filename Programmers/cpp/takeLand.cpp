#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land){
    int answer = 0;
    for(int i=0; i<land.size()-1; i++){
        land[i+1][0] += max(max(land[i][1], land[i][2]), land[i][3]); //같은 열 제외하고
        land[i+1][1] += max(max(land[i][0], land[i][2]), land[i][3]);
        land[i+1][2] += max(max(land[i][0], land[i][1]), land[i][3]);
        land[i+1][3] += max(max(land[i][0], land[i][1]), land[i][2]);
    }
    answer = max(land[land.size()-1][0], max(land[land.size()-1][1], max(land[land.size()-1][2], land[land.size()-1][3])));
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << solution({{1,2,3,5},{5,6,7,8},{4,3,2,1}}) << '\n'; //16
    return 0;
}
