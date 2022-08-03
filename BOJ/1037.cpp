#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int num, arr[51];
    cin >> num;
    for(int i=0; i<num; i++) cin >> arr[i];
    sort(arr, arr+num);
    cout << arr[0] * arr[num-1] << '\n';
    return 0;
}
