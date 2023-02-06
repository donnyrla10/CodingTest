#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, x, y, p1, p2, dis[102] = {0};
vector<int> v[102];

void input(){
    cin >> n >> p1 >> p2 >> m;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
}

void bfs(int s, int e){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int x = q.front(); q.pop();
        if(x==e){
            cout << dis[x] << '\n';
            return;
        }
        
        for(int i=0; i<v[x].size(); i++){ //인접한 노드로 이동
            int y = v[x][i];
            if(dis[y] == 0){ //방문하지 않은 곳
                q.push(y);
                dis[y] = dis[x] + 1;
            }
        }
    }
    
    cout << "-1\n"; //이 안에서 안나오면 가족이 아님
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    bfs(p1, p2);
    return 0;
}
