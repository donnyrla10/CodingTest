#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, arr[1000][1000], d = 0; //0:하, 1:우, 2:상, 3:좌
    int c1, c2, x=0, y=0;
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    cin >> n >> m;
    
    for(int i=n*n; i>0; i--){
        arr[x][y] = i;
        if(i == m) {
            c1 = x+1; c2 = y+1;
        }
        int dx = x + dir[d][0];
        int dy = y + dir[d][1];
        if(dx < 0 || dx >= n || dy < 0 || dy >= n || arr[dx][dy] != 0){ //해당 방향으로 가면 범위에서 벗어나거나 값이 이미 들어간 경우
            d = (d+1)%4; //방향 변경
        }
        x = x + dir[d][0];
        y = y + dir[d][1];
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << c1 << ' ' << c2 << '\n';
    
    return 0;
}
