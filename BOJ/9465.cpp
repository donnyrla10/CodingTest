#include <iostream>
#include <algorithm>
#define num 100002
using namespace std;
int t, n, sticker[num][2];
long long dp[num][2];

//2xn 스티커
//점수의 합이 최대가 되도록 스티커를 떼어내 -> 뗄 수 있는 스티커의 점수의 max value 출력
//스티커 중에서 점수의 합이 최대가 되면서 서로 변을 공유하지 않는 스티커 집합을 구하자
//2xn 스티커니까 2x1~2xn 개의 스티커로 올라오면서 진행해보기

void input(){
    cin >> n;
    for(int i=0; i<2; i++) for(int j=1; j<=n; j++) cin >> dp[j][i];
}

void solution(){
    for(int i=2; i<=n; i++){
        dp[i][0] += max(dp[i-1][1], dp[i-2][1]);
        dp[i][1] += max(dp[i-1][0], dp[i-2][0]);
    }
    cout << max(dp[n][0], dp[n][1]) << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        input();
        solution();
    }
    return 0;
}
