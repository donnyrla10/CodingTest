#include <iostream>
#define num 100002
using namespace std;
int n;
long long dp[num][3];

void input(){
    cin >> n;
}

void solution(){
    //2*1 우리라면, (0, 1) 혹은 (1, 0), (0, 0)
    dp[1][0] = 1; dp[1][1] = 1; dp[1][2] = 1; //초기화
    
    for(int i=2; i<=n; i++){
        dp[i][0] = (dp[i-1][1] + dp[i-1][2])%9901;
        dp[i][1] = (dp[i-1][1] + dp[i-1][2])%9901;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])%9901;
    }
    
    cout << (dp[n][0] + dp[n][1] + dp[n][2])%9901 << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
