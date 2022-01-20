#include <iostream>
#include <algorithm>
using namespace std;
int n, x, arr[1000001], cnt = 0;

void input(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    cin >> x;
}

void solution(){
    int l = 0;
    int r = n-1;
    while(l<r){ //원소 하나 남은 것은 포함하지 않으므르
        int sum = arr[l] + arr[r];
        if(sum == x){ //쌍이 이루어지면
            cnt++;
            l++;
            r--;
        }else if(sum > x){
            r--;
        }else{
            l++;
        }
    }
    cout << cnt << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    sort(arr, arr+n);
    solution();
    return 0;
}
