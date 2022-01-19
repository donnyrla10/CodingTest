#include <iostream>
#include <vector>
using namespace std;
int n, m, x, y, cnt=0;
bool visited[1002] = {false};
vector<int> graph[1002];

void input(){
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}

void dfs(int a){
    visited[a] = true;
    for(int i=0; i<graph[a].size(); i++){
        int b = graph[a][i];
        if(!visited[b]) dfs(b);
    }
}

void solution(){
    for(int i=1; i<=n; i++){
        if(!visited[i]){ //방문하지 않은 정점
            cnt++;
            dfs(i);
        }
    }
    cout << cnt << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
