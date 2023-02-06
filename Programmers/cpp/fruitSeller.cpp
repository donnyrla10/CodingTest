#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <stack>
#include <string>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end());
    int index = score.size() - m;
    while(index >= 0){
        answer += score[index] * m;
        index -= m;
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << solution(3, 4, {1,2,3,1,2,3,1}) << '\n';
    cout << solution(4, 3, {4,1,2,2,4,4,4,4,1,2,4,2}) << '\n';
    return 0;
}
