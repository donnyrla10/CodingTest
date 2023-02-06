#include <iostream>
#define NUM 42
using namespace std;
int m, t;
long long dp[42][2];

void solution(){
    dp[0][0] = 1; dp[1][1] = 1;
    for(int i=2; i<=40; i++){
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    solution();
    while(t--){
        cin >> m;
        cout << dp[m][0] << ' ' << dp[m][1] << '\n';
    }
    return 0;
}
