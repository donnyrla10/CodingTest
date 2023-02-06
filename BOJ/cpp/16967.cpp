#include <iostream>
#include <algorithm>
using namespace std;
int h, w, x, y;
int a[601][601];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> h >> w >> x >> y;
    for(int i=0; i<h+x; i++) for(int j=0; j<w+y; j++) cin >> a[i][j];
    for(int i=x; i<h; i++) for(int j=y; j<w; j++) a[i][j] -= a[i-x][j-y];
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
