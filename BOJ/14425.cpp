#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, cnt=0;
    cin >> n >> m;
    unordered_set<string> se;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        se.insert(s);
    }
    for(int i=0; i<m; i++){
        string s;
        cin >> s;
        if(se.count(s) != 0) cnt++;
        //or
        //if(se.find(s) != se.end()) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
