#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int r, c, ans;
char arr[21][21];
bool visit[21];
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

void DFS(int x, int y, int cnt){
    ans = max(ans, cnt);
    for(int i=0; i<4; i++){
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(0<=dx&&dx<r&&0<=dy&&dy<c && !visit[arr[dx][dy] - 'A']){
            visit[arr[dx][dy] - 'A'] = true;
            DFS(dx, dy, cnt+1);
            visit[arr[dx][dy] - 'A'] = false; //중요 부분!! (다른 방향으로도 이동해야 되기 때문에 꼭 해당 알파벳 방문 체크 해제 해야함
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c;
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) cin >> arr[i][j];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) visit[arr[i][j]-'A'] = false;
    visit[arr[0][0] - 'A'] = true;
    DFS(0, 0, 1);
    cout << ans << '\n';
    return 0;
}
