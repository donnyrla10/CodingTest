#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    if(n < m) swap(n, m);
    int ans = gcd(n, m);
    cout << ans << '\n';
    cout << n * m / ans << '\n';
    return 0;
}
