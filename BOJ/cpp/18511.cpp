#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string n, result;
int k, ans = 0;
vector<int> v;

void BackTracking(){
    if(result.length()>0 && stoi(n) >= stoi(result)){
        ans = max(ans, stoi(result));
    }
    if(result.length() == n.length()){
        return;
    }
    
    for(int i=0; i<v.size(); i++){
        result += to_string(v[i]);
        BackTracking();
        result.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    v.resize(k);
    for(int i=0; i<k; i++) cin >> v[i];
    BackTracking();
    cout << ans << '\n';
    return 0;
}
