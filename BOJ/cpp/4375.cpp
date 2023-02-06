#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    while(cin >> n){
        int tmp = 0;
        for(int i=1; i<=n; i++){
            tmp = tmp * 10 + 1;
            tmp %= n;
            if(tmp == 0) {
                cout << i << '\n'; //자릿수 출력하고 끝내기
                break;
            }
        }
    }
    return 0;
}
