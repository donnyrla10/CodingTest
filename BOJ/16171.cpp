#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s1, s2, s3;
    cin >> s1 >> s2;
    
    for(int i=0; i<s1.size(); i++){
        if(s1[i] >= '0' && s1[i] <= '9') continue;
        s3 += s1[i];
    }
    
    size_t nPos = s3.find(s2);
    if(string::npos != nPos) cout << 1 << '\n';
    else                     cout << 0 << '\n';
    
    return 0;
}
