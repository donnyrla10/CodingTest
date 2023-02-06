#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m, l, w, ans = 0;
char map[51][51];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
queue<pair<int, int>> q;
int dis[51][51];

int BFS(int a, int b){
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) dis[i][j] = -1; //초기화
    dis[a][b] = 0; //0 == 미방문, 1 == 방문
    q.push({a, b});
    int maxD = 0;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(0<=dx&&dx<n&&0<=dy&&dy<m && dis[dx][dy] == -1 && map[dx][dy] == 'L'){ //범위내,미방문,육지
                dis[dx][dy] = dis[x][y] + 1;
                maxD = max(maxD, dis[dx][dy]);
                q.push({dx, dy});
            }
        }
    }
    return maxD;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> map[i][j];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 'L'){
                int d = BFS(i, j);
                ans = max(ans, d);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
