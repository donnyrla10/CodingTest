#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int n, m;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        set<int> n1;
        cin >> n;
        for(int i=0; i<n; i++){
            int a;
            cin >> a;
            n1.insert(a);
        }

        cin >> m;
        for(int i=0; i<m; i++){
            int a;
            cin >> a;
            if(n1.count(a) == 1) cout << "1\n";
            else                 cout << "0\n";
        }
        n1.clear(); //초기화
    }
    return 0;
}
