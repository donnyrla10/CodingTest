#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool visit[9];
vector<int> v;
int ans = -1;

int countDungeons(int tiredness, vector<vector<int>> d){
    int cnt = 0;
    for(int i=0; i<v.size(); i++){
        if(tiredness >= d[v[i]][0]){
            cnt++;
            tiredness -= d[v[i]][1];
        }else{
            break; //tiredness가 더 적으면 더이상 던전 들어갈 수 없음
        }
    }
    return cnt;
}

void BT(int cnt, int dungeon_num, int tiredness, vector<vector<int>> d){
    if(cnt == dungeon_num){
        ans = max(ans, countDungeons(tiredness, d));
        return;
    }
    for(int i=0; i<dungeon_num; i++){
        if(!visit[i]){
            visit[i] = true;
            v.push_back(i); //dungeons 벡터의 i번째 던전 추가
            BT(cnt+1, dungeon_num, tiredness, d);
            v.pop_back();
            visit[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int n = dungeons.size();
    BT(0, n, k, dungeons);
    answer = ans;
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << solution(80, {{80,20}, {50,40}, {30,10}}) << '\n';
    return 0;
}
