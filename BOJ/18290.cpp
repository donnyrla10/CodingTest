#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k, arr[11][11], ans = -2147483648;
bool visit[11][11];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void BT(int cnt, int sum){
    if(cnt == k){ //k개 선택 완료
        ans = max(ans, sum);
        return;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visit[i][j]){
                bool flag = true;
                for(int k=0; k<4; k++){
                    int dx = i + dir[k][0];
                    int dy = j + dir[k][1];
                    if(0<=dx&&dx<n&&0<=dy&&dy<m) if(visit[dx][dy]) flag = false;
                    
                }
                if(flag){
                    visit[i][j] = true;
                    BT(cnt+1, sum+arr[i][j]);
                    visit[i][j] = false;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> arr[i][j];
    BT(0, 0);
    cout << ans << '\n';
    return 0;
}
