#include <iostream>
#include <queue>
#include <algorithm>
using ll = long long;
using namespace std;

ll POW(ll a, ll b, ll c) {
    if(b == 1) return a % c;
    ll val = POW(a, b/2, c);
    val = val * val % c;
    if(b%2==0) return val;
    return val * a % c;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    cout << POW(a, b, c) << '\n';
    return 0;
}
