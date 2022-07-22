#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, arr[31][31], ans = 0;
vector<int> chicken;
bool check[31];

void chooseChicken(int cnt, int s){
    if(cnt == 3){
        int sum = 0;
        for(int i=0; i<n; i++){
            int maxv = 0;
            for(int j=0; j<chicken.size(); j++){
                maxv = max(maxv, arr[i][chicken[j]]);
            }
            sum += maxv;
        }
        ans = max(ans, sum);
        return;
    }
    
    for(int i=s; i<m; i++){
        if(!check[i]){
            check[i] = true;
            chicken.push_back(i);
            chooseChicken(cnt+1, i);
            chicken.pop_back();
            check[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> arr[i][j];
    chooseChicken(0, 0);
    cout << ans << '\n';
    return 0;
}
