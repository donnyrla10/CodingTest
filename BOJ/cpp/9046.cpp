#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int cnt[26] = {0, };
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' ') continue;
            int n = s[i]-'a';
            cnt[n]++;
        }
        int maxN = cnt[0];
        char ans = 'a' + 0;
        for(int i=1; i<26; i++){
            if(maxN < cnt[i]){
                maxN = cnt[i];
                ans = 'a' + i;
            }
        }
        sort(cnt, cnt+26, greater());
        if(cnt[0] == cnt[1]) cout << "?\n";
        else                 cout << ans << '\n';
        
        for(int i=0; i<26; i++) cnt[i] = 0;
    }
    
    return 0;
}
