#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int n, l, r, map[51][51], sum=0, cnt=0;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
bool visited[51][51];
vector<pair<int, int>> v;
bool flag;

//아래 방법에 의해 인구 이동이 없을 때까지 지속
//1. 국경선을 공유하는 두 나라의 인구차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 하루 동안 연다.
//2. 위의 조건에 의해 열려야 하는 국경선이 모두 열렸다면, 인구 이동 시작
//3. 국경선이 열려있어 인접한 칸만 이용해 이동할 수 잇으면, 그 나라를 오늘 하루 동안은 연합이라고 한다
//4. 연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수)/(연합을 이루고 있는 칸의 개수) 가 된다. *소수점버림
//5. 연합을 해체하고 모든 국경선을 닫는다.

//인구이동이 며칠동안 발생하는지 구하는 프로그램

void input(){
    cin >> n >> l >> r;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> map[i][j];
}

void Move(){
    int avg = sum/cnt;
    for(int i=0; i<v.size(); i++){
        int x = v[i].first;
        int y = v[i].second;
        map[x][y] = avg;
    }
}

void bfs(int a, int b){
    queue<pair<int, int>> q;
    q.push({a, b});
    v.push_back({a, b});
    visited[a][b] = true;
    sum += map[a][b];
    cnt++;
    
    //쭉 돌면서 경계선 허물어주기
    while(!q.empty()){
        int x = q.front().first; int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            
            if(dx<0||dy<0||dx>=n||dy>=n) continue;
            if(visited[dx][dy]) continue;
            
            if((l<=abs(map[x][y]-map[dx][dy])) && (r>=abs(map[x][y] - map[dx][dy]))){
                visited[dx][dy] = true;
                sum += map[dx][dy];
                cnt++;
                q.push({dx, dy});
                v.push_back({dx, dy});
            }
        }
    }
    
    //인구 이동
    if(v.size() > 1){
        Move();
        flag = true;
    }
    
    //초기화
    v.clear();
    sum = 0;
    cnt = 0;
}

void solution(){
    int answer = 0;
    while(1){
        memset(visited, false, sizeof(visited));
        flag = false;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]) bfs(i, j);
            }
        }
        
        if(flag) answer++;
        else     break;
    }
    cout << answer << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
