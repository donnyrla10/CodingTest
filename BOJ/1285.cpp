#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, ans = 9999999;
char coin[21][21];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> coin[i][j];
    
    for(int k=0; k <(1<<n); k++){
        int sum = 0;
        for(int j=0; j<n; j++){ //행
            int tCnt = 0;
            for(int i=0; i<n; i++){ //열
                char now = coin[i][j];
                if((1<<i) & k) now = (now == 'H') ? 'T' : 'H';
                if(now == 'T') tCnt++; //T: false, H: true
            }
            sum += min(tCnt, n-tCnt);
        }
        ans = min(ans, sum);
    }
    cout << ans << '\n';
    return 0;
}
