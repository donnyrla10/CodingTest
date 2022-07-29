#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, ans = 0;
vector<int> w;

void BT(int cnt, int power){
    if(cnt == n-2){
        ans = max(ans, power);
        return;
    }
    
    for(int i=1; i<w.size()-1; i++){ //맨 앞, 맨 뒤 제외
        int energy = w[i-1] * w[i+1];
        int now = w[i];
        
        w.erase(w.begin()+i); //현재 아이템 삭제
        BT(cnt+1, power + energy);
        w.insert(w.begin()+i, now);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        int m;
        cin >> m;
        w.push_back(m);
    }
    BT(0, 0);
    cout << ans << '\n';
    return 0;
}
