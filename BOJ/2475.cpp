#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ans = 0;
    for(int i=0; i<5; i++){
        int n;
        cin >> n;
        ans += (n * n);
    }
    cout << ans%10 << '\n';
    return 0;
}
