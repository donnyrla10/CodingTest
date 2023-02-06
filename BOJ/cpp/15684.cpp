#include <iostream>
using namespace std;
int n, m, h;
bool rows[32][12];
int answer = 987654321;

void input() {
    cin >> n >> m >> h;
    while(m--) {
        int a, b;
        cin >> a >> b;
        rows[a][b] = true;
    }
}

bool ladder() {
    for(int j=1; j<=n; j++){
        int c = j;
        for(int i=1; i<=h; i++){
            if(rows[i][c]) c += 1;
            else if(rows[i][c-1]) c -= 1;
        }
        if(c != j) {
            return false;
        }
    }
    return true;
}

void dfs(int k, int until) {
    if(k==until) {
        if(ladder()){
            answer = min(answer, until);
        }
        return;
    }
    for(int j=1; j<n; j++){
        for(int i=1; i<=h; i++){
            //현재 가로선과 양쪽 가로선에 가로선이 있으면 이 가로선 사용 불가
            if(rows[i][j] || rows[i][j+1] || rows[i][j-1]) continue;
            rows[i][j] = true;
            dfs(k+1, until);
            rows[i][j] = false;
            
            while(!rows[i][j-1] && !rows[i][j+1]) i++;
        }
    }
}

void solution() {
    for(int i=0; i<4; i++){
        dfs(0, i);
    }
    if(answer == 987654321) {
        answer = -1;
    }
    cout << answer << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
