#include <iostream>
#include <algorithm>
using namespace std;
int n, arr[1001];
int memo[1001], ans = 0;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> arr[i];
    sort(arr, arr+n+1);
    memo[0] = 0;
    for(int i=1; i<=n; i++){
        memo[i] = memo[i-1] + arr[i];
        ans += memo[i];
    }
    cout << ans << '\n';
    return 0;
}
