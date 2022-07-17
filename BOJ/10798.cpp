#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s[6], ans = "";
    int maxLen = 0;
    for(int i=0; i<5; i++){
        cin >> s[i];
        int l = s[i].size();
        maxLen = max(maxLen, l);
    }
    
    for(int i=0; i<maxLen; i++){
        for(int j=0; j<5; j++){
            if(s[j].length() <= i) continue; //길이가 더 짧으면 넘어가
            ans += s[j][i];
        }
    }
    
    cout << ans << '\n';
    return 0;
}
