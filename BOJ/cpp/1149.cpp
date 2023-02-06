#include <iostream>
#include <algorithm>
#define num 1002
using namespace std;
int n, home[num][4], dp[num][4];

void input(){
    cin >> n;
    for(int i=1; i<=n; i++) for(int j=1; j<=3; j++) cin >> home[i][j];
}

void solution(){
    dp[1][1] = home[1][1]; dp[1][2] = home[1][2]; dp[1][3] = home[1][3]; //초기값
    
    for(int i=2; i<=n; i++){
        dp[i][1] = home[i][1] + min(dp[i-1][2], dp[i-1][3]);
        dp[i][2] = home[i][2] + min(dp[i-1][1], dp[i-1][3]);
        dp[i][3] = home[i][3] + min(dp[i-1][2], dp[i-1][1]);
    }
    
    cout << min(min(dp[n][1],dp[n][2]), dp[n][3]) << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
