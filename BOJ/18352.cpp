#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX 300001
#define INF 0x7fffffff
using namespace std;
int n, m, k, x;
vector<int> graph[MAX];
int dist[MAX];

void input(){
    cin >> n >> m >> k >> x; //도시개수, 도로개수, 거리정보, 출발도시번호
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
}

void BFS(){
    for(int i=0; i<=n; i++) dist[i] = INF;
    queue<int> q;
    q.push(x);
    dist[x] = 0;
    
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int i=0; i<graph[x].size(); i++){
            int y = graph[x][i];
            if(dist[y] != INF) continue;
            if(dist[y] > dist[x] + 1) dist[y] = dist[x] + 1;
            q.push(y);
        }
    }
    
    bool flag = false;
    for(int i=0; i<=n; i++){
        if(dist[i] == k) {
            cout << i << '\n';
            flag = true;
        }
    }
    if(!flag) cout << "-1\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    BFS();
    return 0;
}
