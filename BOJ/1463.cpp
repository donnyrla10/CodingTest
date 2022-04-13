#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution(int x){
    vector<int> dp(x+1);
    dp[1] = 0;
    
    for(int i=2; i<=x; i++){
        dp[i] = dp[i-1] + 1; //1. 1을 뺀다
        if(i%3==0) dp[i] = min(dp[i], dp[i/3]+1);
        if(i%2==0) dp[i] = min(dp[i], dp[i/2]+1);
    }
    
    cout << dp[x] << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x;
    cin >> x;
    solution(x);
    return 0;
}
