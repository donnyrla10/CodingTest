#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    long long t[10001], maxV;
    cin >> n;
    for(int i=0; i<n; i++) cin >> t[i];
    
    sort(t, t+n);
    
    if(n % 2 == 0){ //짝수
        maxV = t[n-1];
        for(int i=0; i<n/2; i++){
            maxV = max(maxV, t[i] + t[n-i-1]);
        }
    }else{          //홀수
        maxV = t[n-1];
        for(int i=0; i<n/2; i++){
            maxV = max(maxV, t[i] + t[n-i-2]);
        }
    }
    cout << maxV << '\n';
    return 0;
}
