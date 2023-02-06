#include <iostream>
#include <queue>
using namespace std;
int n, k, dist[100002];

void input(){
    cin >> n >> k;
}

void BFS(){
    for(int i=0; i<=100000; i++) dist[i] = -1;
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while(!q.empty()){
        int x = q.front(); q.pop();
        int ds[3] = {x-1, x+1, 2*x}; //이동가능한 경로
        for(int i=0; i<3; i++){
            if(ds[i] < 0 || ds[i] > 100000) continue;   //경로 이탈 -> 패스
            if(dist[ds[i]] == -1){                      //방문했던 곳이 아니라면
                dist[ds[i]] = dist[x]+1;
                q.push(ds[i]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    BFS();
    cout << dist[k] << '\n';
    return 0;
}

