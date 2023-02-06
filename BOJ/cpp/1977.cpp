#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> m >> n;
    int ans = n;
    int sum = 0;
    
    for(int i=m; i<=n; i++){
        for(int j=1; j<=i; j++){
            int x = j * j;
            if(i == x) {
                sum += x;
                ans = min(ans, x);
            }
        }
    }
    if(sum == 0) cout << -1 << '\n';
    else         cout << sum << '\n' << ans << '\n';
    return 0;
}
