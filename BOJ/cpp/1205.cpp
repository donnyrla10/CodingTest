#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, ts, p, ans = 0;
    int score[50];
    cin >> n >> ts >> p;
    for(int i=0; i<n; i++) cin >> score[i];
    if(p == n && score[n-1] >= ts) {
        cout << -1 << '\n';
        return 0;
    }
    if(n == 0){
        cout << 1 << '\n';
        return 0;
    }
    
    for(int i=0; i<n; i++){
        if(score[i] > ts) ans++;
        else if(score[i] == ts || score[i] < ts){
            ans++;
            cout << ans << '\n';
            return 0;
        }
    }
    if(score[n-1] >= ts && ans < p) ans++;
    cout << ans << '\n';
    return 0;
}
