#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool visited[10][10] = {false};
vector<pair<int, int>> virus;
int n, m, wall = 3, ans=0, lab[10][10], tmp[10][10], dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

void input(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> lab[i][j];
            if(lab[i][j] == 2) virus.push_back(make_pair(i, j));
        }
    }
}

void BFS(){
    //2. 바이러스 퍼트리기
    queue<pair<int, int>> q;
    for(int i=0; i<virus.size(); i++) q.push(make_pair(virus[i].first, virus[i].second));
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx < 1 || dy < 1 || dx > n || dy > m) continue; //영역 내인지 확인
            if(tmp[dx][dy] != 0) continue;                     //벽/바이러스 영역이면 패스
            q.push(make_pair(dx, dy));
            tmp[dx][dy] = 2;                                   //바이러스 전염!
        }
    }
    
    //3. 안전영역카운트
    int cnt=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(tmp[i][j] == 0) cnt++;
        }
    }
    ans = cnt > ans ? cnt : ans; //가장 큰 값 찾아야 하므로 ans update
}

void solution(){
    //1. 벽세우기(완전탐색)
    if(wall == 0) {
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) tmp[i][j] = lab[i][j]; //벽을 세운 연구소를 복사해서 탐색
        return BFS();
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(lab[i][j] == 0){ //아무것도 없는 곳
                lab[i][j] = 1;  //벽 세우기
                wall--;
                solution();     //재귀호출 -> 앞의 벽들은 고정되고 뒤의 벽의 위치만 변경된다.
                wall++;         //초기화
                lab[i][j] = 0;  //초기화
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    cout << ans << '\n';
    return 0;
}
