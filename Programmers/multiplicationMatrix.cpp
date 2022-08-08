#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for(int i=0; i<arr1.size(); i++){ //arr1 행 개수
        vector<int> v;
        for(int j=0; j<arr2[0].size(); j++){ //arr2 열 개수
            int sum = 0;
            for(int k=0; k<arr1[0].size(); k++){ //arr1 열 개수
                sum += arr1[i][k] * arr2[k][j];
            }
            v.push_back(sum);
        }
        answer.push_back(v);
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<int>> ans = solution({{1,4}, {3,2}, {4,1}}, {{3,3}, {3,3}});
//    vector<vector<int>> ans = solution({{2,3,2}, {4,2,4}, {3,1,4}}, {{5,4,3}, {2,4,1}, {3,1,1}});
    return 0;
}
