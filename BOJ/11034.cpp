#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c;
    while(cin >> a >> b >> c){
        cout << max(b-a, c-b) - 1 << '\n';
    }
    return 0;
}
