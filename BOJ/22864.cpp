#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c, m, h = 24, w = 0, p = 0;
    cin >> a >> b >> c >> m;
    
    while(h--){
        if(p+a <= m){ //일을 해도 m을 넘기지 않는다면 일하기
            p += a;   //피로도 쌓기
            w += b;
        }else{        //일을 하면 m을 넘긴다면 쉬기
            p -= c;   //피로도 줄이기
            if(p < 0) p = 0;
        }
    }
    cout << w << '\n';
    return 0;
}
