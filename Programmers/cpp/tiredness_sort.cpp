#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    sort(dungeons.begin(), dungeons.end());
    do{
        int tiredness = k;
        int cnt = 0;
        for(auto i:dungeons){
            if(tiredness >= i[0]){
                cnt++;
                tiredness -= i[1];
            }
        }
        answer = max(answer, cnt);
    }while(next_permutation(dungeons.begin(), dungeons.end()));
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << solution(80, {{80,20}, {50,40}, {30,10}}) << '\n';
    return 0;
}
