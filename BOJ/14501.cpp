#include <iostream>
#include <algorithm>
#define num 17
using namespace std;
int n, scheduled[num][2], dp[num];


void input(){
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> scheduled[i][0] >> scheduled[i][1]; //duration, payment
    }
}

void solution(){
    int answer = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){     //숫자의 합 i는 i 보다 작은 값으로 이루어지므로 (j: 1, 2, ... , i-1)
            if(scheduled[j][0] + j <= i && scheduled[i][0] + i <= n+1)
                dp[i] = max(dp[i], dp[j] + scheduled[i][1]);
        }
    }
    for(int i=1; i<=n; i++) answer = max(dp[i], answer);
    cout << answer << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
