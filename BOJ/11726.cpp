#include <iostream>
#define NUM 1002
using namespace std;
int Dy[NUM], n;

void solution(){
    Dy[1] = 1; Dy[2] = 2;

    for(int i=3; i<=n; i++){
        Dy[i] = (Dy[i-1] + Dy[i-2]) % 10007 ;
    }
    
    cout << Dy[n] << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    solution();
    return 0;
}
