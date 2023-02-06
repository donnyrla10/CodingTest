#include <iostream>
#include <algorithm>
using namespace std;
int n, a[2002], cnt=0;

void input(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
}

void cal(int index){
    int x = a[index];
    int R = n, L = 1;
    while(L<R){
        if(L == index) L++;         //자기 자신은 덧셈에 포함 안됨
        else if(R == index) R--;    //자기 자신은 덧셈에 포함 안됨
        else{
            if(a[L] + a[R] < x) L++;                        //값이 더 커져야 하므로 작은 값(L)을 증가
            else if(a[L] + a[R] == x) {cnt++; return;}      //합이 x이므로 카운팅
            else R--;                                       //값이 더 작아져야 하므로 큰 값(R)을 감소
        }
    }
}

void solution(){
    sort(a+1, a+n+1);
    for(int i=1; i<=n; i++) cal(i);
    cout << cnt << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
