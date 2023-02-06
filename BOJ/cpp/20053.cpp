#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    vector<int> v;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            int a;
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        cout << v.front() << ' ' << v.back() << '\n';
        v.clear();
    }
    return 0;
}
