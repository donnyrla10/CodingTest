#include <iostream>
#define NUM 15
using namespace std;
int Dy[NUM];

void solution(){
    Dy[1] = 1; Dy[2] = 2; Dy[3] = 4;

    for(int i=4; i<=11; i++){
        Dy[i] = Dy[i-1] + Dy[i-2] + Dy[i-3];
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, n;
    solution();
    cin >> t;
    while(t--){
        cin >> n;
        cout << Dy[n] << '\n';
    }
    return 0;
}
