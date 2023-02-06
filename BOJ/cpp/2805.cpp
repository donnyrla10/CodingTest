#include <iostream>
#include <algorithm>
#define num 1000002
using namespace std;
int n, m, tree[num];

void input(){
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> tree[i];
}

bool cal(long long x){
    long long sum = 0;
    for(int i=0; i<n; i++){
        if(tree[i] > x) sum += tree[i] - x;
    }
    return sum >= m; //가져갈 수 있는 나무의 길이(합)이 원하는 나무의 길이보다 크거나 같으면 true
}

void solution(){
    long long L = 0, R = 2000000000, ans =0;
    while(L <= R){
        long long mid = (L+R)/2;
        if(cal(mid)){ //mid 높이가 가능했기 때문에 더 높은 걸로~
            L = mid + 1;
            ans = mid;
        }else{
            R = mid - 1;
        }
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
