#include <iostream>
#define num 22
using namespace std;
int n, s[num][num], _min = 1000000000;
bool check[num];

void input(){
    cin >> n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin >> s[i][j];
}

void sol(int k, int p){
    if(k == n/2){ //n/2명을 골랐을 경우
        int start = 0;
        int link = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(check[i] && check[j])        start+=s[i][j];
                else if(!check[i] && !check[j]) link+=s[i][j];
            }
        }
        
        int sub = abs(start-link);
        _min = min(_min, sub);
        return;
    }
    
    for(int i=p; i<n; i++){
        check[i] = true;
        sol(k+1, i+1);
        check[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    sol(0, 1);
    cout << _min << '\n';
    return 0;
}
