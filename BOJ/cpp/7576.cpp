#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int m,n,box[1001][1001];
int dir[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
queue<pair<int, int>> q;

void BFS(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(0<=dx&&dx<n&&0<=dy&&dy<m && box[dx][dy] == 0){ //범위내&방문안한&익지않은토마토인경우
                q.push({dx, dy});
                box[dx][dy] = box[x][y] + 1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++){
            cin >> box[i][j];
            if(box[i][j] == 1) q.push({i, j});
        }
    }
    BFS();
    
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(box[i][j] == 0) {
                cout << -1 << '\n';
                return 0;
            }
            
            ans = max(ans, box[i][j]);
        }
    }
    cout << ans - 1 << '\n';
    return 0;
}
