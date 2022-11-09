#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int maxV = 0, cnt = 0, sizeCnt = 0;
int arr[501][501];
bool visit[501][501];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int BFS(int a, int b){
    queue<pair<int, int>> q;
    visit[a][b] = true;
    q.push({a, b});
    
    while(!q.empty()) {
        int x = q.front().first; int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(0 > dx || dx >= n || 0 > dy || dy >= m) continue;
            if(visit[dx][dy] || arr[dx][dy] == 0) continue;
            visit[dx][dy] = true;
            q.push({dx, dy});
            sizeCnt++;
        }
    }
    return sizeCnt;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> arr[i][j];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visit[i][j] && arr[i][j] == 1) {
                cnt++;
                sizeCnt = 1;
                maxV = max(maxV, BFS(i, j));
            }
        }
    }
    cout << cnt << '\n' << maxV << '\n';
    return 0;
}
