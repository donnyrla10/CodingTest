#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, arr[MAX];
    cin >> n >> m;
    for(int i=1; i<=n; i++) arr[i] = i;
    while(m--){
        int begin, end, mid;
        cin >> begin >> end >> mid;
        rotate(arr+begin, arr+mid, arr+end+1);
    }

    for(int i=1; i<=n; i++) cout << arr[i] << ' ';
    return 0;
}
