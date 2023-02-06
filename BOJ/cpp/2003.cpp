//2003번: 수들의 합 2
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, A[10001];

void input(){
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> A[i];
}

void solution(){
    int sum = 0, R = 0, cnt = 0;
    for(int L=1; L<=n; L++){
        sum -= A[L-1];
        while(R+1<=n && sum < m){
            sum += A[++R];
        }
        if(sum == m) cnt++;
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    input();
    solution();
    return 0;
}
