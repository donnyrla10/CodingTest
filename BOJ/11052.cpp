#include <iostream>
#include <algorithm>
#define num 1002
using namespace std;
int n, p[num], dp[num];

void input(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> p[i];
}

void solution(){
    dp[0] = p[0] = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i] = max(dp[i], dp[i-j] + p[j]);
        }
    }
    
    cout << dp[n] << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}

