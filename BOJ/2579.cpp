#include <iostream>
#include <algorithm>
#define num 1002
using namespace std;
int n, stair[num], dp[num][2];

void input(){
    cin >> n;
    stair[0] = 0; //시작점
    for(int i=1; i<=n; i++) cin >> stair[i];
}

void solution(){
    dp[1][0] = 0; dp[1][1] = stair[1];
    if(n>=2){
        dp[2][0] = stair[2];
        dp[2][1] = stair[1] + stair[2];
    }
    
    for(int i=3; i<=n; i++){
        dp[i][0] = stair[i] + max(dp[i-2][0], dp[i-2][1]); //max 값을 넣어야 됨
        dp[i][1] = stair[i] + dp[i-1][0]; //3번 연속으로 오를 수 없기 때문
    }
    cout << max(dp[n][0], dp[n][1]) << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
