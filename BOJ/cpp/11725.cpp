#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, n1, n2, parent[100002];
vector<int> v[100002];
bool visited[100002];

void input(){
    cin >> n;
    for(int i=0; i<n-1; i++){
        cin >> n1 >> n2;
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
}

void bfs(int s){
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int i=0; i<v[x].size(); i++){
            int y = v[x][i];
            if(visited[y]) continue; //방문한적이 있으면 패스
            parent[y] = x;           //부모 노드 번호 저장
            visited[y] = true;
            q.push(y);
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    bfs(1);
    for(int i=2; i<=n; i++) cout << parent[i] << '\n';
    return 0;
}
