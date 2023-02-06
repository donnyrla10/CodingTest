#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int l, p, v, cnt, index = 0;
    
    while(1){
        cin >> l >> p >> v;
        if(l==0 && p==0 && v==0) break;
        
        cnt = 0; //초기화
        cnt += (v/p) * l;
        if((v%p) < l) cnt += v % p;
        else          cnt += l;
        cout << "Case " << index+1 << ": " << cnt << '\n';
        index++;
    }
    return 0;
}
