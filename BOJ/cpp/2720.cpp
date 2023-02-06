#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    int money[4] = {25, 10, 5, 1};
    int ans[4];
    cin >> t;
    while(t--){
        int c;
        cin >> c;
        for(int i=0; i<4; i++){
            ans[i] = c / money[i];
            c %= money[i];
        }
        for(int i=0; i<4; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}
