#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, arr[50000], sum=0;
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    for(int i=0; i<n-1; i++) sum += arr[i];
    cout << sum << '\n';
    return 0;
}
