#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define NUM 1002
using namespace std;
int t, n, k, w, T[NUM], sum[NUM], indeg[NUM], X, Y;
vector<int> graph[NUM];

void solution(){
    queue<int> q;
    //1. 들어오는 간선이 없는 정점부터 시작 -> queue에 넣기
    for(int i=1; i<=n; i++) if(indeg[i] == 0) {q.push(i); sum[i] = T[i];}
    
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int i : graph[x]){
            indeg[i]--;
            if(indeg[i] == 0) q.push(i);
            sum[i] = max(sum[i], sum[x]+T[i]); //더 큰 값 (더 오래 걸리는 시간을 합해야 하므로)
        }
    }
    cout << sum[w] << '\n';
}

void input(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=1; i<=n; i++) {
            cin >> T[i];        //건물 당 걸리는 시간
            indeg[i] = 0;       //초기화
            sum[i] = 0;         //초기화
            graph[i].clear();   //초기화
        }
        for(int i=1; i<=k; i++){
            cin >> X >> Y;
            graph[X].push_back(Y);
            indeg[Y]++;
        }
        cin >> w;
        solution();
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    return 0;
}

