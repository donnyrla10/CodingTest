#include <iostream>
#include <queue>
#include <vector>
#define MAX 10001
#define inf 0x7fffffff
using namespace std;
int n, dest, dist[MAX];
vector<pair<int, int>> route[MAX];

void input(){
    cin >> n >> dest;
    
    for(int i=0; i<=dest-1; i++)
        route[i].push_back({i+1, 1});
    
    for(int i=0; i<n; i++){
        int from, to, weight;
        cin >> from >> to >> weight;
        route[from].push_back({to, weight});
    }
}

void BFS(){
    fill_n(dist, MAX, inf);
    queue<pair<int, int>> q; //vertex, distance
    
    q.push({0, 0});
    dist[0] = 0;

    while(!q.empty()){
        //보고있는 정점의 정보 -> v: 정점번호, d: 시작점부터의 거리
        int v = q.front().first; int d = q.front().second;
        q.pop();
        
        if(d > dist[v]) continue; //최신 정보와 다르면 패스

        for(auto& y : route[v]){
            auto [to, dis] = y;
            if(dist[to] > dist[v] + dis){
                dist[to] = dist[v] + dis;
                q.push({to, dist[to]});
            }
        }
    }
    
    cout << dist[dest] << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    BFS();
    return 0;
}
