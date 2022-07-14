#include <iostream>
#include <vector>
using namespace std;
int n, m, cnt=0;
bool ch[205][205];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        ch[a][b] = ch[b][a] = true; //섞어먹으면 안되는 조합의 아이스크림 번호
    }
    
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(ch[i][j]) continue; //섞어 먹으면 안되는 조합
            for(int k=j+1; k<=n; k++){
                if(ch[i][k] || ch[j][k]) continue; //섞어 먹으면 안되는 조합
                ++cnt;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
