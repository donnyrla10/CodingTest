#include <iostream>
#include <algorithm>
#define num 12
using namespace std;
int n, number[num], op[5];
int _max = -1000000000, _min = 1000000000;

void input(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> number[i];
    for(int i=1; i<=4; i++) cin >> op[i];
}

int operation(int op1, int op, int op2){
    switch(op){
        case 1: return op1 + op2;
        case 2: return op1 - op2;
        case 3: return op1 * op2;
        case 4: return op1 / op2;
        default: return -1;
    }
}

void rf(int k, int total){
    if(k==n){
        _max = max(_max, total);
        _min = min(_min, total);
        return;
    }
    
    for(int i=1; i<=4; i++){
        if(op[i] != 0){
            op[i]--;
            rf(k+1, operation(total, i, number[k+1]));
            op[i]++;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    rf(1, number[1]);
    cout << _max << '\n' << _min << '\n';
    return 0;
}
