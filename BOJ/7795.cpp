#include <iostream>
#include <algorithm>
#define MAX 20002
using namespace std;
int t, n, m, A[MAX], B[MAX], cnt=0;

void input(){
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> A[i];
    for(int i=0; i<m; i++) cin >> B[i];
}

void binarySearch(int x){
    int l = 0, r = m-1;
    while(l <= r){ //원소가 하나만 남아도 됨
        int mid = (l+r)/2;
        if(x <= B[mid]){
            r = mid - 1;
        }else{
            cnt++;
            l = l + 1;
        }
    }//탐색 완료
}

void solution(){
    sort(B, B+m); //작아먹히는 B 정렬
    cnt = 0;
    for(int i=0; i<n; i++){
        binarySearch(A[i]);
    }
    cout << cnt << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        input();
        solution();
    }
    return 0;
}
