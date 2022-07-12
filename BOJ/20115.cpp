#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    vector<int> v;
    cin >> n;
    for(int i=0; i<n; i++){
        int m;
        cin >> m;
        v.push_back(m);
    }
    sort(v.begin(), v.end(), greater());
    
    double a = v[0];
    for(int i=1; i<n; i++){
        double b = a + ((double)v[i] / 2);
        a = b;
    }
    cout << a << '\n';
    return 0;
}
