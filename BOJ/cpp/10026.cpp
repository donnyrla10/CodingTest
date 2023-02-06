#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n;
char arr[101][101];
bool visit[101][101];
queue<pair<int, int>> q;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void BFS(int a, int b){
    visit[a][b] = true;
    q.push({a, b});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(0<=dx&&dx<n&&0<=dy&&dy<n && !visit[dx][dy] && arr[dx][dy] == arr[x][y]){ //범위내&방문하지않은곳&동일한 색
                visit[dx][dy] = true;
                q.push({dx, dy});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    
    //적록색약이 아닌 사람
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visit[i][j]){
                cnt++;
                BFS(i, j);
            }
        }
    }
    cout << cnt << ' ';
    cnt = 0;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) visit[i][j] = false; //초기화
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(arr[i][j] == 'G') arr[i][j] = 'R';
    
    //적록색약인 사람
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visit[i][j]){
                cnt++;
                BFS(i, j);
            }
        }
    }
    cout << cnt << '\n';
    
    return 0;
}
