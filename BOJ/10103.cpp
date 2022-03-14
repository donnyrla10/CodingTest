#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, A=100, B=100;
    cin >> n;
    while(n--){
        int a, b;
        cin >> a >> b;
        if(a<b)      A-=b;
        else if(a>b) B-=a;
    }
    cout << A << '\n' << B << '\n';
    return 0;
}

