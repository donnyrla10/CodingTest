#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, lope[100001], ans = 0;
    cin >> n;
    for(int i=0; i<n; i++) cin >> lope[i];
    
    sort(lope, lope+n);
    int num = n;
    for(int i=0; i<n; i++){
        ans = max(ans, num * lope[i]);
        num--;
    }
    cout << ans << '\n';
    return 0;
}
