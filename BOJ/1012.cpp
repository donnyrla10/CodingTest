#include <iostream>
using namespace std;
int t, n, m, k, x, y, cnt = 0;
bool visited[51][51];
int a[51][51], dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(int nx, int ny){
    visited[nx][ny] = true;
    for(int i=0; i<4; i++){
        int dx = nx + dir[i][0];
        int dy = ny + dir[i][1];
        if(dx < 0 || dy < 0 || dx >= n || dy >= m) continue;
        if(a[dx][dy] == 0) continue;
        if(visited[dx][dy]) continue;
        dfs(dx, dy);
    }
}

void solution(){
    cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && a[i][j] == 1){
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> m >> n >> k;
        for(int i=0; i<n; i++) for (int j=0; j<m; j++) a[i][j] = 0; //초기화
        for(int i=0; i<n; i++) for (int j=0; j<m; j++) visited[i][j] = false; //초기화
        for(int i=0; i<k; i++){
            cin >> y >> x;
            a[x][y] = 1;
        }
        solution();
    }
    return 0;
}
