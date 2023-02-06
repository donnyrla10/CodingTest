#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, cnt = 0;
    
    cin >> a >> b;
    while(1){
        if(b < a){
            cout << "-1\n";
            return 0;
        }
        if(b == a){
            cout << cnt+1 << '\n';
            return 0;
        }
        
        if(b % 2 == 0){
            cnt++;
            b /= 2;
        }else if(b%10==1){
            cnt++;
            b--;
            b /= 10;
        }else{
            cout << -1 << '\n';
            break;
        }
    }
    return 0;
}
