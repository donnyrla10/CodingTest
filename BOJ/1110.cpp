#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, cnt = 0, tmp = 0, ten, one;
    cin >> n;
    if(n < 10) ten = 0;
    else       ten = n / 10;
    one = n % 10;
    
    do{
        tmp = one*10 + (ten+one)%10;
        ten = tmp / 10;
        one = tmp % 10;
        cnt++;
    }while(tmp != n);
    cout << cnt << '\n';
    return 0;
}
