#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
bool num[1000001];
int MAX = 1000000;
vector<int> v;

//소수 먼저 찾아놓기
void primeNum(){
    for(int i=2; i<=MAX; i++) num[i] = true;
    for(int i=2; i<=sqrt(MAX); i++){
        if(!num[i]) continue;
        for(int j=i*i; j<=MAX; j+=i) num[j] = false;
    }
    for(int i=2; i<MAX; i++) if(num[i]) v.push_back(i);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    
    primeNum();
    while(1){
        cin >> n;
        if(n==0) break;
        
        bool flag = false;
        for(int i=1; v[i] < n; i++){
            int n2 = n - v[i];
            if(num[n2]){
                cout << n << " = " << v[i] << " + " << n2 << '\n';
                flag = true;
                break;
            }
        }
        if(!flag) cout << "Goldbach's conjecture is wrong.\n";
    }
    return 0;
}
