#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define inf 0x7fffffff
#define MAX 10001
using namespace std;
int n, m, x;
vector<pair<int, int>> st[MAX];
int dist[MAX];

//1. 각자 자신의 집에서 X로 가는데 걸리는 시간을 dist[]에 저장한다.
//2. X에서 각자 자신의 집으로 돌아가는데 걸리는 시간을 dist[]에 추가로 더해준다.

void input(){
    cin >> n >> m >> x;
    for(int i=0; i<m; i++){
        int from, to, time;
        cin >> from >> to >> time;
        //단방향
        st[from].push_back({to, time});
    }
}

void Dijk(int start, int end){
    for(int i=1; i<=n; i++) dist[i] = inf;
    queue<pair<int, int>> q;
    q.push({start, 0});
    dist[start] = 0;
    
    while(!q.empty()){
        int curV = q.front().first;
        int curT = q.front().second;
        q.pop();
        
        if(curT > dist[curV]) continue;
        
        for(auto& next : st[curV]){
            auto [nextV, nextT] = next;
            if(dist[nextV] > dist[curV] + nextT){
                dist[nextV] = dist[curV] + nextT;
                q.push({nextV, dist[nextV]});
            }
        }
    }
}

void solution(){
    int total_dist[n+1];
    
    for(int i=1; i<=n; i++){
        //1. 각자 집(i)에서 x로 가는데 걸리는 최소 시간!
        Dijk(i, x);
        total_dist[i] = dist[x];
        //2. x에서 각자 집(i)으로 돌아가는데 걸리는 최소 시간!
        Dijk(x, i);
        total_dist[i] += dist[i];
    }

    int _max = -1;
    for(int i=1; i<=n; i++) _max = max(_max, total_dist[i]);
    cout << _max << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
