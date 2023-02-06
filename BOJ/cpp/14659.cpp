#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, cnt=0, ans = 0;
    vector<int> v;
    cin >> n;
    for(int i=0; i<n; i++){
        int h;
        cin >> h;
        v.push_back(h);
    }
    
    for(int i=0; i<n; i++){
        cnt = 0;
        for(int j=i+1; j<n; j++){
            if(v[i] < v[j]){
                i = j-1;
                break;
            }else{
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}
