#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, cnt=1;
    vector<pair<int, int>> v;
    cin >> n;
    for(int i=0; i<n; i++){
        int s, e;
        cin >> s >> e;
        v.push_back({e, s});
    }
    
    sort(v.begin(), v.end());
    
    int time = v[0].first;
    for(int i=1; i<n; i++){
        if(time <= v[i].second){ //다음 s 시작 시간 >= 현재 s 종료시간
            cnt++;
            time = v[i].first;
        }
    }
    
    cout << cnt << '\n';
    return 0;
}
