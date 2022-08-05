#include <iostream>
#include <algorithm>
using namespace std;
int n, arr[21], s, ans = 0;

void BT(int cnt, int sum){
    if(cnt == n){ //arr의 끝까지 간 경우
        if(sum == s) ans++;
        return;
    }
    
    BT(cnt+1, sum + arr[cnt]);  //현재 수열 더하기
    BT(cnt+1, sum);             //현재 수열 더하지 않기
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n); //정렬
    BT(0, 0);
    if(s==0) ans--;
    cout << ans << '\n';
    return 0;
}
