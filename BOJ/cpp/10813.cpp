#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    int basket[102];
    
    cin >> n >> m;
    for(int i=1; i<=n; i++) basket[i] = i;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        swap(basket[x], basket[y]);
    }
    
    for(int i=1; i<=n; i++) cout << basket[i] << ' ';
    cout << '\n';
    return 0;
}

