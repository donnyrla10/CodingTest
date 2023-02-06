#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int eureka[1001];

bool check(int n){
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            for(int k=1; k<n; k++){
                if(eureka[i] + eureka[j] + eureka[k] == n) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(int i=1; i<=1000; i++) eureka[i] = i*(i+1)/2;
    while(t--){
        int n;
        cin >> n;
        cout << check(n) << '\n';
    }
    return 0;
}
