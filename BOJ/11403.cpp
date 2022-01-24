#include <iostream>
#include <queue>
using namespace std;
int n, graph[102][102];
bool visited[102];

void input(){
    cin >> n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin >> graph[i][j];
}

void bfs(int i){
    for(int k=1; k<=n; k++) visited[k] = false;
    queue<int> q;
    q.push(i);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int y=1; y<=n; y++){
            if(graph[x][y] == 0 || visited[y]) continue; //방문했거나 0이라면 넘어간다.
            visited[y] = true;
            q.push(y);
        }
    }
    for(int k=1; k<=n; k++) visited[k] ? cout << "1 " : cout << "0 ";
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    for(int i=1;i<=n;i++) bfs(i);
    return 0;
}
