#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
bool visit[101];
queue<int> q;

int BFS(int start, vector<vector<int>> tmp){
    int cnt = 1;
    visit[start] = true;
    q.push(start);
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0; i<tmp.size(); i++){
            if(tmp[i][0] == x){
                int y = tmp[i][1];
                if(!visit[y]){
                    cnt++;
                    visit[y] = true;
                    q.push(y);
                }
            }else if(tmp[i][1] == x){
                int y = tmp[i][0];
                if(!visit[y]){
                    cnt++;
                    visit[y] = true;
                    q.push(y);
                }
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    for(int i=0; i<n-1; i++){
        vector<vector<int>> tmp = wires;
        tmp.erase(tmp.begin() + i);             //간선 하나 제거
        memset(visit, false, n+1);              //visit 초기화
        int firstCnt = 0, secondCnt = 0;        //각 집합 정점 개수 초기화
        bool flag = false;
        for(int j=1; j<=n; j++){
            if(!visit[j]){
                if(!flag){
                    firstCnt = BFS(j, tmp);
                    flag = true;
                }else{
                    secondCnt = BFS(j, tmp);
                }
            }
        }
        answer = min(answer, abs(firstCnt - secondCnt));
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << solution(9, {{1,3}, {2,3}, {3,4}, {4,5}, {4,6}, {4,7}, {7,8}, {7,9}}) << '\n'; //3
//    cout << solution(4, {{1,2}, {2,3}, {3,4}}) << '\n'; //0
//    cout << solution(7, {{1,2}, {2,7}, {3,7}, {3,4}, {4,5}, {6,7}}) << '\n'; //1
    return 0;
}
