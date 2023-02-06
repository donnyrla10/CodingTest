#include <iostream>
using namespace std;
int dp[100001];

int F(int n){
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i=2; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) %1234567;
    }
    return dp[n];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int answer = 0;
    int n = 5;
    answer = F(n);
    cout << answer << '\n';
    return 0;
}
