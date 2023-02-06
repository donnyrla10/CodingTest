#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, cnt=0;
    cin >> n;
    vector<int> tree;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        tree.push_back(t);
    }
    sort(tree.begin(), tree.end(), greater());
    for(int i=0; i<n; i++) cnt = max(cnt, tree[i]+i+1);
    cout << cnt+1 << '\n';
    return 0;
}
