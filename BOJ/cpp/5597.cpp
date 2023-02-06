#include <iostream>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n = 28;
    set<int> s;
    while(n--){
        int a;
        cin >> a;
        s.insert(a);
    }
    for(int i=1; i<=30; i++){
        if(s.count(i) == 0) cout << i << '\n';
    }
    return 0;
}
