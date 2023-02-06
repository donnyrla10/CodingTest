#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int E, S, M;
    cin >> E >> S >> M;
    int e=1, s=1, m=1;
    int cnt = 1;
    while(1){
        if(e == E && s == S && m == M) break;
        e = (e == 15) ? 1 : e+1;
        s = (s == 28) ? 1 : s+1;
        m = (m == 19) ? 1 : m+1;
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
