#include <iostream>
#include <queue>
#define MAX 52
using namespace std;
int room[MAX][MAX], n, m, clean_cnt=0;
int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}}; //북, 동, 남, 서

void DFS(int x, int y, int d){
    //빈공간인지 체크
    if(room[x][y] == 0){
        room[x][y] = 2; //청소 표시!
        clean_cnt++;
    }
    
    for(int i=1; i<=4; i++){
        int dd = (4+(d-i))%4;
        int dx = x + dir[dd][0];
        int dy = y + dir[dd][1];
        
        if(dx<0||dy<0||dx>=n||dy>=m||room[dx][dy]==1) continue; //범위 벗어나거나 벽이면 패스
        
        if(room[dx][dy] == 0) DFS(dx, dy, dd);
    }
    
    //여기 온거면 네 방향 모두 청소한 상태!
    //후진할 수 있는지 보고 할 수 있으면 DFS 계속 ㄱㄱ
    //벽이면 후진 못하므로 카운팅 출력하고 끝
    int bd = (d+2)%4;
    int bx = x + dir[bd][0];
    int by = y + dir[bd][1];
    
    if(room[bx][by] == 1){
        cout << clean_cnt << '\n';
        exit(0); //바로 종료!
    }
    DFS(bx, by, d);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int x, y, d;
    cin >> x >> y >> d;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> room[i][j];
    DFS(x, y, d);
    return 0;
}

