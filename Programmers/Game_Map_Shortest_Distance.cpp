#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dis[101][101];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int BFS(int r, int c, vector<vector<int> > map, int n, int m){
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) dis[i][j] = 0;
    queue<pair<int, int>> q;
    q.push({r, c});
    dis[r][c] = 1;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x == n-1 && y == m-1) return dis[x][y];
        
        for(int i=0; i<4; i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(0<=dx&&dx<n&&0<=dy&&dy<m && dis[dx][dy] == 0 && map[dx][dy] != 0){
                dis[dx][dy] = dis[x][y] + 1;
                q.push({dx, dy});
            }
        }
    }
    
    return dis[n-1][m-1];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<int> > maps = {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}};
    int r = maps.size(); int c = maps[0].size();
    int answer = 0;
    
    if(maps[r-1][c-2] == 0 && maps[r-2][c-1] == 0) answer = -1;
    else{
        answer = BFS(0, 0, maps, r, c);
        if(answer == 0) answer = -1;
    }    cout << answer << '\n';
    return 0;
}
