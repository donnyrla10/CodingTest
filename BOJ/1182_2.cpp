#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, arr[21], s, ans = 0;
    cin >> n >> s;
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=1; i<(1<<n); i++){ //1부터 시작 = 공집합 제외
        int sum = 0;
        for(int j=0; j<n; j++){ //0 ~ n-1 돌면서 해당 부분집합이 어떤 index의 원소를 가지는지 확인
            if(i & (1<<j)) sum += arr[j]; //부분집합에 들어있으면 해당 값을 더해준다.
        }
        if(sum == s) ans++;
    }
    cout << ans << '\n';
    return 0;
}
