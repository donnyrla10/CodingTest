#include <iostream>
#include <queue>
using namespace std;
int n, m, X, Y, dist[502][502];
int dir[8][2] = {{-2,-1}, {-2,1}, {-1,-2}, {-1,2}, {1,-2}, {1,2}, {2,-1}, {2,1}};

void input(){
    cin >> n >> m;
    cin >> X >> Y;
}

void BFS(){
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) dist[i][j] = -1;
    queue<pair<int, int>> q;
    q.push({X, Y});
    dist[X][Y] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<8; i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx < 1 || dy < 1 || dx > n || dy > n) continue; //경로이탈 pass
            if(dist[dx][dy] != -1) continue;                   //방문한 곳 pass
            dist[dx][dy] = dist[x][y] + 1;
            q.push({dx, dy});
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    BFS();
    for(int i=0; i<m; i++) {
        int horseX, horseY;
        cin >> horseX >> horseY;
        cout << dist[horseX][horseY] << ' ';
    }
    cout << '\n';
    return 0;
}
