#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m, k, arr[101][101];
bool visit[101][101];
queue<pair<int, int>> q;
vector<int> cnt;
int dir[4][2] = {{1, 0}, {0, 1}, {-1,0}, {0,-1}};

int BFS(int a, int b){
    int blank = 1;
    q.push({a, b});
    visit[a][b] = true;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(0<=dx&&dx<m&&0<=dy&&dy<n && !visit[dx][dy] && arr[dx][dy] != 1){
                q.push({dx, dy});
                blank++;
                visit[dx][dy] = true;
            }
        }
    }
    return blank;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n >> k;
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) arr[i][j] = 0; //초기화
    
    for(int i=0; i<k; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int tmp = x1;
        x1 = m - y1;
        y1 = tmp;
        tmp = x2;
        x2 = m - y2;
        y2 = tmp;
        for(int i=x2; i<x1; i++) for(int j=y1; j<y2; j++) arr[i][j] = 1;
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!visit[i][j] && arr[i][j] != 1){
                int x = BFS(i, j);
                cnt.push_back(x);
            }
        }
    }
    cout << cnt.size() << '\n';
    sort(cnt.begin(), cnt.end());
    for(auto i: cnt) cout << i << ' ';
    cout << '\n';
    return 0;
}
