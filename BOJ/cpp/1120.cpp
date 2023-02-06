#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string A, B;

void solution(){
    int minI = 51, cnt = 0;
    size_t LA = A.length(), LB = B.length();
    for(int i=0; i<=LB-LA; ++i){
        cnt = 0;
        for(int j=0; j<LA; ++j){
            if(A[j] != B[j+i]) cnt++;
        }
        minI = min(minI, cnt);
    }
    
    cout << minI << '\n';
}

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> A >> B;
    solution();
    return 0;
}
