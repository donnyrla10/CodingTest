#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int m, n;
int num[1000001];

void primeNumber(){
    for(int i=2; i<=n; i++) num[i] = i;
    for(int i=2; i<=sqrt(n); i++){
        if(num[i] == 0) continue; //num[i]가 0이면 소수가 아니므로 continue
        for(int j=i*i; j<=n; j+=i) num[j] = 0; //i*k(i<k)까지의 수는 이미 검사했으므로 i*i부터 검사
    }
    for(int i=m; i<=n; i++) if(num[i] != 0) cout << num[i] << '\n'; //출력
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    primeNumber();
    return 0;
}
