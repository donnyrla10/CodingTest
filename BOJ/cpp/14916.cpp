#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, cnt=2147483647;
    cin >> n;
    
    int u = n / 5;
    for(int i=0; i<=u; i++){ //5원을 0개부터 u개 사용하는 경우
        int m = n, c = i;
        m -= 5 * i;
        c += m / 2;
        m %= 2;
        if(m == 0){
            cnt = min(cnt, c);
        }
    }
    if(cnt == 2147483647) cout << "-1\n";
    else                  cout << cnt << '\n';
    return 0;
}
