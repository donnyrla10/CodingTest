#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, number[20001], _max = -1, _min = 1000000000, ans;


void input(){
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> number[i];
        _max = max(_max, number[i]);
    }
}

void solution(){
    for(int k=1; k<=_max; k++){
        int sum = 0;
        for(int i=0; i<n; i++) sum += abs(number[i] - k);

        if(_min > sum){
            _min = sum;
            ans = k;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    input();
    solution();
    return 0;
}
