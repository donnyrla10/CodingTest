#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, s[21][21], ans = 40001;
bool check[21];

void compareStartLink(){
    vector<int> start, link;
    int sAB = 0, lAB = 0;
    
    for(int i=0; i<n; i++){
        if(check[i]) start.push_back(i);
        else         link.push_back(i);
    }
    
    for(int i=0; i<start.size(); i++){
        for(int j=i+1; j<start.size(); j++){
            sAB += (s[start[i]][start[j]] + s[start[j]][start[i]]);
        }
    }
    for(int i=0; i<link.size(); i++){
        for(int j=i+1; j<link.size(); j++){
            lAB += (s[link[i]][link[j]] + s[link[j]][link[i]]);
        }
    }
    
    ans = min(ans, abs(sAB - lAB));
}

void BT(int cnt, int s, int member){
    if(cnt == member){
        compareStartLink();
        return;
    }
    
    for(int i=s; i<n; i++){
        if(!check[i]){
            check[i] = true;
            BT(cnt+1, i+1, member);
            check[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> s[i][j];
    for(int i=2; i<n-1; i++) BT(0, 0, i);
    cout << ans << '\n';
    return 0;
}
