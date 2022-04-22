#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c, d, e;
    int time = 0;
    bool frozen = true;
    cin >> a >> b >> c >> d >> e;
    
    while(a != b){
        if(a < 0){
            frozen = true;
            time += c * abs(a);
            a = 0;
        }else if(a == 0 && frozen){
            time += d;
            frozen = false;
        }else if(a >= 0){
            time += e * (b-a);
            a = b;
        }
    }
    
    cout << time << '\n';
    return 0;
}

