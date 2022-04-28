#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAX 102
using namespace std;
int n, arr[MAX][MAX], maxR = -1;
bool visited[MAX][MAX];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void Raining(int x){
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) visited[i][j] = false; //초기화
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(arr[i][j] <= x) arr[i][j] = 0;
}

void bfs(int sx, int sy){
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    
    while(!q.empty()){
        int x = q.front().first; int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            
            if(dx < 0 || dy < 0 || dx >= n || dy >= n) continue;
            if(visited[dx][dy] || arr[dx][dy] == 0) continue;
            
            visited[dx][dy] = true;
            q.push({dx, dy});
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int answer = 0;
    
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
            maxR = max(maxR, arr[i][j]);
        }
    }
        
    for(int i=0; i<maxR; i++){
        int cnt = 0;
        //비 내리기
        Raining(i);
        
        //안전 영역 카운팅
        for(int i=0; i<n; i++){ //비가 전혀 오지 않을 경우가 있으므로 0부터 시작
            for(int j=0; j<n; j++){
                if(arr[i][j] != 0 && !visited[i][j]){
                    bfs(i, j);
                    cnt++;
                }
            }
            answer = max(answer, cnt);
        }
    }
    
    cout << answer << '\n';
    return 0;
}
