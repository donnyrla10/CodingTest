#include <iostream>
#define num 1002
using namespace std;
int n, dp[num][10];

void solution(){
    for(int i=0; i<10; i++) dp[1][i] = 1; //초기값 -> i자릿수이고 1로 끝나는 수
    for(int len=2; len<=n; len++){
        //자리수 len 이고 last로 끝나는 수
        for(int last=0; last<10; last++){
            for(int prev=0; prev<=last; prev++){
                dp[len][last] += dp[len-1][prev];
                dp[len][last] %= 10007;
            }
        }
    }
    
    int ans = 0;
    for(int i=0; i<10; i++){
        ans += dp[n][i];
        ans %= 10007;
    }
    cout << ans << '\n';
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    solution();
    return 0;
}

