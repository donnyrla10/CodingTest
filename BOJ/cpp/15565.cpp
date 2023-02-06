#include <iostream>
#include <algorithm>
using namespace std;
int n, k, doll[1000002], minS = 1000001;

void input(){
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> doll[i];
}

void solution(){
    int cnt = 0, R = 0;
    for(int L=1; L<=n; L++){
        if(doll[L-1] == 1) cnt--;
        while(R+1<=n && cnt < k){
            if(doll[++R] == 1) cnt++;
        }
        if(cnt >= k) minS = min(R-L+1, minS);
    }
    if(minS == 1000001) cout << "-1\n";
    else         cout << minS << '\n';
}

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    input();
    solution();
    return 0;
}
