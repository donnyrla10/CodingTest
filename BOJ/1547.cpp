#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m, pos = 1;
    cin >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        if(pos == x) pos = y;
        else if(pos == y) pos = x;
    }
    cout << pos << '\n';
    return 0;
}
