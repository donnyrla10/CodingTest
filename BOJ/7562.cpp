#include <iostream>
#include <queue>
using namespace std;
int t, I, startX, startY, endX, endY;
int dir[8][2] = {{-1, 2}, {-2, 1}, {1, 2}, {2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
int dis[302][302] = {-1};

void BFS(){
    queue<pair<int, int>> q;
    q.push({startX, startY});
    dis[startX][startY] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<8; i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx < 0 || dy < 0 || dx > I || dy > I) continue;
            if(dis[dx][dy] != -1) continue; //방문한 곳이므로 패스
            dis[dx][dy] = dis[x][y] + 1;
            q.push({dx, dy});
        }
    }
    cout << dis[endX][endY] << '\n';
}

void input(){
    cin >> t;
    while(t--){
        cin >> I;
        cin >> startX >> startY >> endX >> endY;
        for(int i=0; i<I; i++) for(int j=0; j<I; j++) dis[i][j] = -1; //거리(방문체크) 초기화
        BFS();
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    return 0;
}

