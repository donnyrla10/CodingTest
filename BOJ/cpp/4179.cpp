#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int r, c;
string arr[1001];
int dist1[1001][1001]; //j
int dist2[1001][1001]; //f
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue<pair<int, int>> q1; //j
queue<pair<int, int>> q2; //f

void FireBFS(){
    while(!q2.empty()) {
        int x = q2.front().first; int y = q2.front().second;
        q2.pop();
        for(int i=0; i<4; i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(0 > dx || dx >= r || 0 > dy || dy >= c) continue; //범위 벗어나는 경우 패스
            if(dist2[dx][dy] >= 0 || arr[dx][dy] == '#') continue; //방문한 곳이거나 벽인 경우 패스
            dist2[dx][dy] = dist2[x][y] + 1;
            q2.push({dx, dy});
        }
    }
}

void JBFS(){
    while(!q1.empty()) {
        int x = q1.front().first; int y = q1.front().second;
        q1.pop();
        for(int i=0; i<4; i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(0 > dx || dx >= r || 0 > dy || dy >= c) { //범위 벗어나는 경우, 지훈이가 무사히 빠져나옴
                cout << dist1[x][y] + 1 << '\n';
                return;
            }
            if(dist1[dx][dy] >= 0 || arr[dx][dy] == '#') continue; //방문한 곳이거나 벽인 경우 패스
            //불이 방문한 곳이고, 나보다 먼저 도착한 경우 -> 여기는 못감(불났으므로)
            if(dist2[dx][dy] != -1 && dist2[dx][dy] <= dist1[x][y] + 1) continue;
            dist1[dx][dy] = dist1[x][y] + 1;
            q1.push({dx, dy});
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c;
    for(int i=0; i<r; i++){
        fill(dist1[i], dist1[i]+c, -1);
        fill(dist2[i], dist2[i]+c, -1);
    }
    for(int i=0; i<r; i++) {
        cin >> arr[i];
        for(int j=0; j<c; j++){
            if(arr[i][j] == 'F'){
                q2.push({i, j});
                dist2[i][j] = 0; //방문 체크
            }else if(arr[i][j] == 'J'){
                q1.push({i, j});
                dist1[i][j] = 0;
            }
        }
    }
    FireBFS();
    JBFS();
    return 0;
}
