#include <iostream>
using namespace std;
int n, m, ans = 0;
int money[6] = {500, 100, 50, 10, 5, 1};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    m = 1000 - n;
    
    for(int i=0; i<6; i++){
        ans += m / money[i];
        m %= money[i];
    }
    cout << ans << '\n';
    return 0;
}
