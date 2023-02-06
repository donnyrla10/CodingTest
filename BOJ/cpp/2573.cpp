#include <iostream>
#include <queue>
#define MAX 301
using namespace std;
int n, m, area[MAX][MAX];
int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
bool visited[MAX][MAX];

void BFS(int a, int b){
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = true;
    
    while(!q.empty()){
        int x = q.front().first; int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            
            if(dx<0||dy<0||dx>=n||dy>=m) continue; //범위 넘어가거나 방문한 곳이면 패스
            if(area[dx][dy] == 0 || visited[dx][dy]) continue;
            visited[dx][dy] = true;
            q.push({dx,dy});
        }
    }
}

void melting(){
    int tmp[n][m];
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) tmp[i][j] = area[i][j];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(area[i][j] != 0){
                for(int k=0; k<4; k++){
                    int ni = i + dir[k][0];
                    int nj = j + dir[k][1];
                    if(ni<0||nj<0||ni>=n||nj>=m) continue;
                    if(area[ni][nj] == 0 && tmp[i][j] >= 1) tmp[i][j]--;
                }
            }
        }
    }
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) area[i][j] = tmp[i][j];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int year = 0, chunk = 0;
    
    cin >> n >> m;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> area[i][j];
    

    while(1){
        chunk = 0; //초기화(덩어리 개수)
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) visited[i][j] = false;
        
        for(int i=0; i<n; i++){ //덩어리 개수
            for(int j=0; j<m; j++){
                if(!visited[i][j] && area[i][j] != 0){
                    BFS(i, j);
                    chunk++;
                }
            }
        }
        if(chunk >= 2) { //while 반복문 나가는 조건 1 : 빙산이 2개 이상으로 분리됨
            cout << year << '\n';
            break;
        }
        if(chunk == 0){ //while 반복문 나가는 조건 2 : 빙산이 다 녹을때까지 분리되지 않으면 0
            cout << "0\n";
            break;
        }
        
        melting(); //빙하 녹이기
        year++;
    }
    return 0;
}
