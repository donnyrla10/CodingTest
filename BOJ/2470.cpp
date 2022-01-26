//두 포인터
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, a[100001];

void input(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
}

void solution(){
    sort(a, a+n); //sorting
    int sum = 2000000001, L = 0, R =n-1, ans1=0, ans2=0;
    
    while(L<R){ //원소가 하나남은 경우는 포함되지 않으므로 '<'
        if(sum > abs(a[L] + a[R])){ //min value
            sum = abs(a[L] + a[R]); //update
            ans1 = L;
            ans2 = R;
        }
        a[L]+a[R] > 0 ? R-- : L++;
    }
    
    cout << a[ans1] << ' ' << a[ans2] << '\n';
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
