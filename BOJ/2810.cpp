#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, ans;
    float cnt = 0;
    string s; //좌석 배치
    cin >> n >> s;
    
    ans = n + 1;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'L'){
            cnt += 0.5;
        }
    }
    if(cnt == 0) cout << n << '\n';
    else         cout << ans - cnt << '\n';
    return 0;
}
