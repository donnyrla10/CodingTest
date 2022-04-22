#include <iostream>
using namespace std;

//바구니 n개 (1~n번) - 초기엔 공이 없음. 바구니엔 공 1개만 넣을 수 있음
//M번 공을 넣으려고 할 때, 공을 넣을 바구니 범위를 정하고, 정한 바구니에 모든 같은 번호가 적혀있는 공을 넣는다.
//만약 공이 이미 있으면 들어있는 공을 빼고, 새로 공을 넣는다. 공 넣을 바구니는 연속적
//공을 어떻게 넣을지 주어졌을 때, m번 공을 넣은 이후에 각 바구니에 어떤 공이 들어있는지 구하자.

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    int basket[102];
    
    cin >> n >> m;
    for(int i=1; i<=n; i++) basket[i] = 0; //초기화
    
    for(int i=1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        for(int j=a; j<=b; j++){
            basket[j] = c;
        }
    }
    for(int i=1; i<=n; i++) cout << basket[i] << ' ';
    cout << '\n';
    return 0;
}
