#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[100002], b;

bool BS(int x){
    int l = 0, r = n-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(x == a[mid]) return true;
        if(x > a[mid])  l = mid + 1;
        else            r = mid - 1;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> b;
        BS(b) ? cout << "1\n" : cout << "0\n";
    }
    return 0;
}
