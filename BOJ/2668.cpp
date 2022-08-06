#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;
int n;
int arr[101];
set<int> ans;
bool check[101];
bool ok = false;

void DFS(int start, int next){
    if(check[next]){ //방문한 곳이라면
        if(start == next){ //시작했던 수에 다시 방문하는 경우(사이클O)
            ok = true;
            ans.insert(next);
        }
        return;
    }
    
    check[next] = true;
    DFS(start, arr[next]); //시작 수, 다음(사이클)
    if(ok){
        ans.insert(next);
        ans.insert(arr[next]);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> arr[i];
    
    for(int i=1; i<=n; i++){
        check[i] = true;
        DFS(i, arr[i]);
        memset(check, false, n+1);
        ok = false; //initialized
    }
    cout << ans.size() << '\n';
    for(auto i : ans) cout << i << '\n';
    return 0;
}
