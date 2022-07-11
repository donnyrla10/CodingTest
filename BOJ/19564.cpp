#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int len = s.size(), ans=0;
    for(int i=0; i<len-1; i++){
        int n = s[i] - '0';
        int m = s[i+1] - '0';
        if(n >= m) ans++;
    }
    cout << ans+1 << '\n';
    return 0;
}
