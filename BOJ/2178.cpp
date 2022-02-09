#include <iostream>
#include <queue>
using namespace std;
int n, m, miro[101][101];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dis[101][101];
string s;

void input(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> s;
        for(int j=0; j<m; j++) miro[i+1][j+1] = s[j] - '0';
    }
}

void BFS(){
    queue<pair<int, int>> q;
    q.push({1, 1}); //출발 위치
    dis[1][1] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx < 1 || dy < 1 || dx > n || dy > m) continue; //범위 밖 - 패스
            if(miro[dx][dy] == 0) continue; //이동불가한 곳 - 패스
            if(dis[dx][dy] != 0) continue; //방문한 곳 - 패스
            dis[dx][dy] = dis[x][y] + 1;
            q.push({dx, dy});
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    BFS();
    cout << dis[n][m] << '\n';
    return 0;
}
