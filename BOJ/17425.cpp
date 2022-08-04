#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;
long long dp[1000001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    
    for(int i=1; i<=MAX; i++) for(int j=i; j<= MAX; j+=i) dp[j] += i;
    for(int i=2; i<=MAX; i++) dp[i] += dp[i-1];
    
    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}
