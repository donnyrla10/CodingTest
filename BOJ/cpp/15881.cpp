#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, cnt = 0;
    string s;
    cin >> n >> s;
    
    for(int i=0; i<n; i++){
        if(s.substr(i, 4) == "pPAp"){
            cnt++;
            i += 3;
        }
    }
    cout << cnt << '\n';
    return 0;
}
