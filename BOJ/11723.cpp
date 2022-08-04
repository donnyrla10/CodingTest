#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m;
    cin >> m;
    string str;
    int n, bit = 0;
    while(m--){
        cin >> str;
        if(str == "add"){
            cin >> n;
            bit |= (1<<n); //n번째 자리수를 1로 바꾼다
        }else if(str == "remove"){
            cin >> n;
            bit &= ~(1<<n); //n번째 자릿수를 없앤다 (0으로, 아님 무시)
        }else if(str == "check"){
            cin >> n;
            if(bit & (1<<n)) cout << 1 << '\n'; //n번째 자릿수 있/없
            else             cout << 0 << '\n';
        }else if(str == "toggle"){
            cin >> n;
            bit ^= (1<<n); //n번째 자릿수 flip
        }else if(str == "all"){
            bit = (1<<21) - 1; //10000-1 = 1111
        }else if(str == "empty"){
            bit = 0;
        }
    }
    return 0;
}
