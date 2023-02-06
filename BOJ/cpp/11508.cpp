#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, c[100001], ans = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> c[i];
        ans += c[i];
    }
    sort(c, c+n, greater());
    for(int i=2; i<n; i+=3){
        ans -= c[i];
    }
    cout << ans << '\n';
    return 0;
}
