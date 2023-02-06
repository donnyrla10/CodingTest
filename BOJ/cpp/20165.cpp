#include <iostream>
#include <algorithm>
#include <queue>
#define num 102
using namespace std;
int n, m, r, game[num][num];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int ax, ay, dx, dy, score;
char adir, state[num][num];

void input(){
    cin >> n >> m >> r;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> game[i][j];
            state[i][j] = 'S';
        }
    }
}

int checkDir(char adir){
    switch(adir){
        case 'E': return 0;
        case 'W': return 1;
        case 'S': return 3;
        case 'N': return 2;
        default : return -1;
    }
}

void attack(){
    queue<pair<int, int>> q;
    q.push({ax, ay});
    state[ax][ay] = 'F'; //넘어짐 -> 'F'
    score++;
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        int h = game[x][y];
        for(int i=1; i<h; i++){
            int nx = x + dir[checkDir(adir)][1] * i;
            int ny = y + dir[checkDir(adir)][0] * i;
            if(nx < 1 || ny < 1 || nx > n || ny > m) continue; //격자를 벗어난 경우 패스
            if(state[nx][ny] == 'F')                 continue; //넘어져있는 상태의 도미노인 경우 패스
            q.push({nx, ny});
            state[nx][ny] = 'F';
            score++;
        }
    }
}

void defend(){
    //해당 위치 초기화
    state[dx][dy] = 'S';
}

void printResult(){
    cout << score << '\n';
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << state[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    while(r--){
        cin >> ax >> ay >> adir;
        cin >> dx >> dy;
        attack(); //공격
        defend(); //수비
    }
    printResult();
    return 0;
}
