#include <iostream>
#include <vector>
using namespace std;
int w, h;
int map[52][52], dir[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {-1, 1}};
bool visited[52][52];


// i = width = x, j = height = y
// 2차원 배열 [i][j] 에서 i = y(row), j = x(column)

void input(){
    for(int i=0; i<w; i++) for(int j=0; j<h; j++) {map[i][j] = 0; visited[i][j] = false;} //initialize
    for(int i=0; i<w; i++) for(int j=0; j<h; j++) cin >> map[i][j];
}

void dfs(int x, int y){
    visited[x][y] = true;
    for(int i=0; i<8; i++){
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(dx < 0 || dy < 0 || dx >= w || dy >= h) continue;
        if(map[dx][dy] == 0) continue;
        if(visited[dx][dy]) continue;
        dfs(dx, dy);
    }
}

void solution(){
    int cnt = 0;
    for(int i=0; i<w; i++){
        for(int j=0; j<h; j++){
            if(!visited[i][j] && map[i][j] == 1){
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(true){
        cin >> h >> w;
        if(w == 0 && h == 0) break;
        input();
        solution();
    }
    return 0;
}
