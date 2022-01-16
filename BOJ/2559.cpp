//2559번: 수열
#include <iostream>
#include <algorithm>
using namespace std;
int n, k, temp[100001];

void input(){
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> temp[i];
}

void solution(){
    int sum = 0, R = 0, maxT = -10000000;
    for(int L=1; L <= n-k+1; L++){ //L의 범위는 k를 더한 값보다 작아야된다!
        sum -= temp[L-1];
        while(R+1 <= L+k-1){
            sum += temp[++R];
        }
        maxT = max(maxT, sum);
    }
    cout << maxT << '\n';
}

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    input();
    solution();
    return 0;
}
