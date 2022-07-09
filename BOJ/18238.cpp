#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    
    int cnt1 = 0; int cnt2 = 0;
    int ans = 0;
    char cur = 'A';
     
    for(int i=0; i<s.size(); i++){
        cnt1 = abs(s[i] - cur); //현재 위치의 문자와의 목표 문자(s[i])와 길이
        cnt2 = 26 - cnt1; //반대 방향
        
        ans += min(cnt1, cnt2);
        cur = s[i];
        
    }
    cout << ans << '\n';
    return 0;
}
