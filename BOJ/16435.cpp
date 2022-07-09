#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, l, h[1001];
    cin >> n >> l;
    for(int i=0; i<n; i++) cin >> h[i];
    sort(h, h+n);
    
    for(int i=0; i<n; i++){
        if(l >= h[i]){
            l++;
        }else{
            cout << l << '\n';
            return 0;
        }
    }
    cout << l << '\n';
    return 0;
}
