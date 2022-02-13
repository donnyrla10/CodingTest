#include <iostream>
#include <queue>
using namespace std;
int R, S;
int water_dist[52][52], hedgehog_dist[52][52], dir[4][2] = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};
char map[52][52];

void input(){
    cin >> R >> S;
    for(int i=0; i<R; i++) for(int j=0; j<S; j++) cin >> map[i][j];
}

void BFS_water(){
    //물은 여러 곳에서 시작할 수 있으므로 모두 queue에 넣고 진행한다
    queue<pair<int, int>> q;
    for(int i=0; i<R; i++) {
        for(int j=0; j<S; j++) {
            water_dist[i][j] = -1;
            if(map[i][j] == '*'){
                q.push({i, j});
                water_dist[i][j] = 0; //방문체크
            }
        }
    }
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int dx = x + dir[i][0], dy = y + dir[i][1];
            if(dx < 0 || dy < 0 || dx >= R || dy >= S) continue; //지도 범위 이탈 pass
            if(water_dist[dx][dy] != -1) continue;               //방문한 곳 pass
            if(map[dx][dy] != '.') continue;                     //갈 수 없는 곳 pass
            water_dist[dx][dy] = water_dist[x][y] + 1;           //시간 기록 -> 고슴도치 이동 시 이동가능한지 체크 O
            q.push({dx, dy});
        }
    }
}

void BFS_hedgehog(){
    queue<pair<int, int>> q;
    for(int i=0; i<R; i++) {
        for(int j=0; j<S; j++) {
            hedgehog_dist[i][j] = -1;
            if(map[i][j] == 'S'){
                q.push({i, j});
                hedgehog_dist[i][j] = 0;
            }
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int dx = x + dir[i][0], dy = y + dir[i][1];
            if(dx < 0 || dy < 0 || dx >= R || dy >= S) continue;
            if(map[dx][dy] != '.' && map[dx][dy] != 'D') continue;
            if(water_dist[dx][dy] != -1 && water_dist[dx][dy] <= hedgehog_dist[x][y] + 1) continue; //이미 물에 잠긴 곳 (물이 찰 예정인 곳)
            if(hedgehog_dist[dx][dy] != -1) continue; //이미 방문한 곳
            hedgehog_dist[dx][dy] = hedgehog_dist[x][y] + 1;
            q.push({dx, dy});
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    BFS_water();
    BFS_hedgehog();
    for(int i=0; i<R; i++){
        for(int j=0; j<S; j++) {
            if(map[i][j] == 'D') hedgehog_dist[i][j] == -1 ? cout << "KAKTUS\n" : cout << hedgehog_dist[i][j] << '\n';
        }
    }
    return 0;
}

