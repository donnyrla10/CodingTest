#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, arr[1000001], b, c;
    long long cnt=0;
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    cin >> b >> c;
    
    for(int i=0; i<n; i++){
        int person = arr[i];
        if(person >= b){
            person -= b;
            cnt++;
        }else{
            cnt++;
            person = 0;
        }
        
        if(person != 0) cnt += (person - 1) / c + 1;
    }
    cout << cnt << '\n';
    return 0;
}
