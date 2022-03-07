#include <iostream>
#define num 92
using namespace std;
int n;
long long dp[num][3];

void input(){
    cin >> n; //n자리 이친수 개수 구하기
}

void solution(){
    dp[1][1] = 1; dp[1][0] = 0; //초기값
    
    for(int i=2; i<=n; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    
    cout << dp[n][0] + dp[n][1] << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
