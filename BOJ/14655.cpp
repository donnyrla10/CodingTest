#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, ans=0;
    cin >> n;
    for(int i=0; i<n*2; i++){
        int m;
        cin >> m;
        ans += abs(m);
    }
    cout << ans << '\n';
    return 0;
}
