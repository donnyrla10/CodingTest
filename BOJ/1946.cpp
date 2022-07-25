#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    pair<int, int> p[100001];
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        for(int i=0; i<n; i++) cin >> p[i].first >> p[i].second;
        
        sort(p, p+n);
        
        int ans = 1;
        int interview = p[0].second; //서류심사 1위인 사람의 인터뷰 점수
        
        for(int i=1; i<n; i++){
            if(p[i].second < interview){
                ans++;
                interview = p[i].second;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
