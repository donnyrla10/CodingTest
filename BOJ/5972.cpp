#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 50002
#define inf 0x7fffffff
using namespace std;
int n, m;
vector<pair<int, int>> road[MAX];
int dist[MAX];

void input(){
    cin >> n >> m; //헛간 개수, 소들의 길 개수
    for(int i=0; i<m; i++){
        int from, to, cow;
        cin >> from >> to >> cow;
        road[from].push_back({to, cow});
        road[to].push_back({from, cow});
    }
}

void BFS(){
    fill_n(dist, MAX, inf);
    queue<pair<int, int>> q;
    q.push({1, 0}); //1에서 시작
    dist[1] = 0;
    
    while(!q.empty()){
        int v = q.front().first; int d = q.front().second;
        q.pop();
        if(d > dist[v]) continue; //더 길면 패스
        for(auto& j : road[v]){
            auto [to, cow] = j;
            if(dist[to] > dist[v] + cow) {
                dist[to] = dist[v] + cow;
                q.push({to, dist[to]});
            }
        }
    }
    
    cout << dist[n] << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    BFS();
    return 0;
}
