#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#define num 20002
using namespace std;

int dist[num];

void bfs(int s, vector<int> g[]){
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int i=0; i<g[x].size(); i++){
            int y = g[x][i];
            if(dist[y] != -1) continue; //방문한 곳이라면 패스
            dist[y] = dist[x] + 1;
            q.push(y);
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    vector<int> graph[n+1];
    int answer = 0;
    int Max = 0;
    for(int i = 0; i<edge.size(); i++){
        graph[edge[i][0]].push_back(edge[i][1]); //양방향이므로 둘다 저장
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    for(int i=1; i<=n; i++) dist[i] = -1; //거리 초기화
    bfs(1, graph);
    for(int i=1; i<=n; i++) Max = Max < dist[i] ? dist[i] : Max; //가장 멀리 떨어진 거리 max 구하기
    for(int i=1; i<=n; i++) if(Max == dist[i]) answer++; //가장 멀리 떨어진 노드 카운팅
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<int>> e = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};
    int n = 6;
    cout << solution(n, e) << '\n';
    return 0;
}
