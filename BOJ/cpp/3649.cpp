#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long x;
    int arr[1000001], nm = 10000000;
    vector<pair<int, int>> v;
    while(cin >> x){ //x = 구멍 너비, 단위 cm
        x *= nm;
        int n;
        cin >> n;    //블록 길이, 단위 nm (나노미터)
        for(int i=0; i<n; i++) cin >> arr[i];
        sort(arr, arr+n); //정렬
        
        int L = 0, R = n-1;
        while(L < R){
            long long value = arr[L] + arr[R];
            if(value > x) R--;
            else if(value < x) L++;
            else {
                v.push_back({arr[L], arr[R]});
                L++; R--;
            }
        }
        
        if(v.empty()) {
            cout << "danger\n";
            continue;
        }
        int maxv = abs(v[0].first - v[0].second);
        int ans1 = v[0].first, ans2 = v[0].second;
        if(v.size() > 1){
            for(int i=1; i<v.size(); i++){
                if(maxv < abs(v[i].first - v[i].second)){
                    maxv = abs(v[i].first - v[i].second);
                    ans1 = v[i].first;
                    ans2 = v[i].second;
                }
            }
        }
        cout << "yes ";
        if(ans1 >= ans2) cout << ans2 << ' ' << ans1 << '\n';
        else             cout << ans1 << ' ' << ans2 << '\n';
        v.clear();
    }
    return 0;
}
