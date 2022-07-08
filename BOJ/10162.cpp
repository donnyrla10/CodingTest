#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    int button[3] = {300, 60, 10};
    int abc[3] = {0, 0, 0};
    cin >> t;
    
    for(int i=0; i<3; i++){
        abc[i] = t / button[i];
        t %= button[i];
    }
    
    if(t != 0) cout << "-1\n";
    else       cout << abc[0] << ' ' << abc[1] << ' ' << abc[2] << '\n';
    return 0;
}
