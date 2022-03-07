#include <iostream>
#include <algorithm>
#define num 10002
using namespace std;
int n, wine[num], dp[num][2];

void input(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> wine[i];
}

void solution(){
    dp[1][0] = wine[1]; dp[1][1] = wine[1];
    
    if(n>=2){
        dp[2][0] = wine[1] + wine[2];
        dp[2][1] = wine[2];
    }

    for(int i=3; i<=n; i++){
        dp[i][1] = wine[i] + max(dp[i-2][0], dp[i-2][1]); //두 잔 넘긴 상태
        dp[i][1] = max(dp[i][1], max(dp[i-3][0], dp[i-3][1]) + wine[i]); //두 잔을 연속으로 안먹은 상태
        dp[i][0] = wine[i] + dp[i-1][1];
    }
    
    cout << max({dp[n][0], dp[n][1], dp[n-1][0], dp[n-1][1]}) << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
