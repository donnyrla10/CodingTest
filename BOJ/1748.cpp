#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, ans = 0;
    cin >> n;
    
    for(int i=1; i<=n; i*=10){
        ans += n-i+1;
    }
    //i자리수의 개수를 센다
    
    cout << ans << '\n';
    return 0;
}
