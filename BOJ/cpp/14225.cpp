#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;
int n, S[21], sum = 0;
vector<int> v;
set<int> num;
bool check[21];
int m = 1, ans = 0;

void BT(int cnt, int s, int k){
    if(cnt == k){
        sum = 0;
        for(auto i : v) sum += i;
        num.insert(sum);
        return;
    }
    
    for(int i=s; i<n; i++){
        if(!check[i]){
            check[i] = true;
            v.push_back(S[i]);
            BT(cnt+1,i,k);
            v.pop_back();
            check[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) cin >> S[i];
    sort(S, S+n);
    
    for(int i=1; i<=n; i++){ //부분수열 N=3 -> 1, 2, 3
        BT(0,0,i);
    }
    
    int ans = 1;
    while(1){
        if(num.find(ans) == num.end()){
            cout << ans << '\n';
            return 0;
        }else{
            ans++;
        }
    }
    return 0;
}
