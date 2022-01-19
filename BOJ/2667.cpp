#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, cnt;
char map[26][26];
bool visited[26][26];
int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<int> group;

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
}

void dfs(int x, int y){
    cnt++;
    visited[x][y] = true;
    for(int i=0; i<4; i++){
        int dx = x + direction[i][0];
        int dy = y + direction[i][1];
        if(dx < 0 || dy < 0 || dx >= n || dy >= n) continue; //지도를 벗어난 경우
        if(map[dx][dy] == '0') continue;                     //1이 아닌 경우
        if(visited[dx][dy]) continue;                        //방문한 집인 경우
        dfs(dx, dy);
    }
}

void solution(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && map[i][j] == '1'){
                cnt = 0;
                dfs(i, j);
                group.push_back(cnt);
            }
        }
    }
    sort(group.begin(), group.end());
    cout << group.size() << '\n';
    for(auto it = group.begin(); it != group.end(); it++) cout << *it << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
