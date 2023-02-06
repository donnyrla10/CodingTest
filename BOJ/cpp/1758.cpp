#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, p[100001];
    long long tip=0;
    cin >> n;
    for(int i=0; i<n; i++) cin >> p[i];
    sort(p, p+n, greater());
    
    for(int i=0; i<n; i++){
        int m = p[i] - i;
        if(m < 0) m = 0;
        tip += m;
    }
    cout << tip << '\n';
    return 0;
}
