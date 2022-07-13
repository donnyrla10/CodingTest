#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, cnt = 0;
    cin >> n >> k;
    for(int h=0; h<=n; h++){
        for(int m=0; m<60; m++){
            for(int s=0; s<60; s++){
                if(h % 10 == k || h / 10 == k || m / 10 == k || m % 10 == k || s / 10 == k || s % 10 == k) cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
