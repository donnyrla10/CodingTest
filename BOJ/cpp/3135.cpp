#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, n, ans=0;
    cin >> a >> b >> n;
    int closest = a;
    
    //가장 가까운 값 구하기
    for(int i=0; i<n; i++) {
        int bt;
        cin >> bt;
        if(abs(b-closest) > abs(b-bt)) closest = bt;
    }
    if(closest != a) ans++;
    
    while(1){
        if(b == closest) break;
        
        //감소 혹은 증가
        if(closest > b){ //B버튼
            closest--;
            ans++;
        }else{ //A버튼
            closest++;
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
