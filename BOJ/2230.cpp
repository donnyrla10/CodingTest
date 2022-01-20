#include <iostream>
#include <algorithm>
#include <cmath>
typedef long long ll;
using namespace std;
int n, A[100001];
ll m;

void input(){
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> A[i];
}

void solution(){
    sort(A, A+n);
    int R = 0;
    ll ans = 2000000001;
    for(int L=0; L<n; L++){
        while(R+1 < n && A[R] - A[L] < m) ++R;
        if (A[R] - A[L] >= m) ans = ans > A[R] - A[L] ? (A[R] - A[L]) : ans; //최소 구하기
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
