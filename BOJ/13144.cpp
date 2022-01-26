#include <iostream>
using namespace std;
int n, a[100002];
bool check[100002];

void input(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
}

void solution(){
    int R = 0;
    long ans = 0;
    for(int L = 1; L <= n; L++){
        while(R+1<=n && !check[a[R+1]]){ //R이 범위내에 있고 중복된 값이 아니라면
            check[a[++R]] = true; //다음으로 넘어가고 해당 원소값 체크
        }
        ans += R - L + 1; //카운팅 값
        check[a[L]] = false; //초기화
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
