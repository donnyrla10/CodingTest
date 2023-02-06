#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <stack>
using namespace std;

int t, w, h;
string arr[1001];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue<pair<int, int>> q;
int disFire[1001][1001];
int disSG[1001][1001];

void BFS_fire(){
    while(!q.empty()) {
        int x = q.front().first; int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(0 > dx || dx >= h || 0 > dy || dy >= w) continue;
            if(arr[dx][dy] == '#') continue;
            if(disFire[dx][dy] != 0) continue;
            disFire[dx][dy] = disFire[x][y] + 1;
            q.push({dx, dy});
        }
    }
}

void BFS_sg(){
    while(!q.empty()) {
        int x = q.front().first; int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(0 > dx || dx >= h || 0 > dy || dy >= w) { //탈출한 경우
                cout << disSG[x][y] << '\n';
                return;
            }
            if(disFire[dx][dy] != 0 && disFire[dx][dy] <= disSG[x][y] + 1) continue; //불이 옮겨진 곳이나 불을 곳은 이동 불가
            if(disSG[dx][dy] == 0 && arr[dx][dy] == '.') {
                disSG[dx][dy] = disSG[x][y] + 1;
                q.push({dx, dy});
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> w >> h;
        for(int i=0; i<h; i++) cin >> arr[i];
        //불
        for(int i=0; i<h; i++) fill(disFire[i], disFire[i]+w, 0);
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(arr[i][j] == '*') {
                    q.push({i, j});
                    disFire[i][j] = 1;
                }
            }
        }
        BFS_fire();
        //상근이
        for(int i=0; i<h; i++) fill(disSG[i], disSG[i]+w, 0);
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(arr[i][j] == '@') {
                    q.push({i, j});
                    disSG[i][j] = 1;
                }
            }
        }
        BFS_sg();
    }
    return 0;
}
