#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, ans;
    cin >> s;
    ans = s[0];
    for(int i=1; i<s.size(); i++){
        if(s[i] == '-' && i+1 < s.size()){
            ans += s[i+1];
        }
    }
    cout << ans << '\n';
    return 0;
}
