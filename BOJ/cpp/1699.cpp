#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution(int n){
    vector<int> dp(n+1);
    // 나보다 작거나 같은 '제곱수(^2)'들의 합으로 나타낼 수 있다.
    for(int i=1; i<=n; i++){
        dp[i] = i;
        for(int j=1; j*j<=i; j++) //제곱수들 체크
            dp[i] = min(dp[i], dp[i-j*j] + 1);
    }
    cout << dp[n] << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    solution(n);
    return 0;
}
