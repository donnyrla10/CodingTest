#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, arr[11][11];
int ans = 10000000;
bool visit[11];
vector<int> v;

void BT(int cnt){
    if(cnt == n){
        int sum = 0;
        for(int i=0; i<v.size(); i++){
            if(i == n-1){
                if(arr[v[i]][v[0]] == 0) return;
                sum += arr[v[i]][v[0]];
            }else{
                if(arr[v[i]][v[i+1]] == 0) return;
                sum += arr[v[i]][v[i+1]];
            }
        }
        ans = min(ans, sum);
        return;
    }
    
    for(int i=0; i<n; i++){
        if(!visit[i]){
            visit[i] = true;
            v.push_back(i);
            BT(cnt+1);
            visit[i] = false;
            v.pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> arr[i][j];
    BT(0);
    cout << ans << '\n';
    return 0;
}
