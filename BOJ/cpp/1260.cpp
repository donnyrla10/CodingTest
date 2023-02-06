#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, v, a, b;

bool visited[1001];
vector<int> graph[1001];

void input(){
    cin >> n >> m >> v;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); //중요
    }
    for(int i=1; i<=n; i++) sort(graph[i].begin(), graph[i].end()); //작은 것을 고르기로 했으므로 정렬해줌
}

void dfs(int x){
    cout << x << " ";
    visited[x] = true;
    for(int i=0; i<graph[x].size(); i++){
        int y = graph[x][i];
        if(!visited[y]) dfs(y);
    }
}

void bfs(int start){
    for(int i=0; i<1001; i++) visited[i] = false;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int x = q.front();
        cout << x << ' ';
        q.pop();
        for(int i=0; i<graph[x].size(); i++){
            int y = graph[x][i];
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    dfs(v);
    cout << '\n';
    bfs(v);
    return 0;
}
