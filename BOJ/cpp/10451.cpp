#include <iostream>
#include <vector>
#include <queue>
#define num 1002
using namespace std;
int n;
bool visited[num];
vector<int> graph[num];

void input(){
    cin >> n;
    for(int i=1; i<=n; i++){visited[i]=false; graph[i].clear();} //초기화
    
    for(int i=1; i<=n; i++){
        int a;
        cin >> a;
        graph[i].push_back(a); //i에서 a로 간선을 이어 그래프를 만든다.
    }
}

void BFS(int z){
    queue<int> q;
    q.push(z);
    visited[z] = true;
    while(!q.empty()){
        int x = q.front(); q.pop();
        int y = graph[x][0];
        if(visited[y]) continue; //방문한 곳이면 패스
        visited[y] = true;
        q.push(y);
    }
}

void solution(){
    int cnt = 0; //counting 초기화
    for(int i=1; i<=n; i++) {
        if(!visited[i]){
            cnt++;
            BFS(i);
        }
    }
    cout << cnt << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        input();
        solution();
    }
    return 0;
}
