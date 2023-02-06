#include <iostream>
#define num 66
using namespace std;
int n;
long long dp[num][10]; //dp[i][j] => i개의 자릿수, j로 끝나는 경우의 수

//어떤 숫자가 줄어들지 않는 다는 것은 그 숫자의 각 자리 수보다 그 왼쪽 자리 수가 작거나 같을 때이다.
//예를 들어, 1234는 줄어들지 않는다.
//숫자의 맨 앞에 0이 있어도 된다. -> 0000, 0001, 0002는 올바른 줄어들지 않는 수
//n이 주어졌을 때, 줄어들지 않는 n자리 수의 개수를 구하자

void solution(){
    //초기값
    for(int j=0; j<=9; j++){ //0~9
        dp[1][j] = 1;
    }
    
    for(int i=2; i<=n; i++){ //i개의 자릿수
        long long sum = 0;
        for(int j=0; j<=9; j++){ //j로 끝나는 경우의 수
            dp[i][j] = dp[i-1][j] + sum;
            sum += dp[i-1][j];
        }
    }
    
    long long answer = 0;
    for(int i=0; i<=9; i++)
        answer += dp[n][i];
    cout << answer << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        solution();
    }
    return 0;
}
