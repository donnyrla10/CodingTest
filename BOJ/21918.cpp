#include <iostream>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    bool bulb[4000];
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> bulb[i];
    
    //command
    for(int i=0; i<m; i++){
        int comm, a, b;
        cin >> comm >> a >> b;
        if(comm == 1)               bulb[a] = b;
        else if(comm == 2){
            for(int i=a; i<=b; i++) bulb[i] = !bulb[i];
        }else if(comm == 3){
            for(int i=a; i<=b; i++) bulb[i] = 0;
        }else if(comm == 4){
            for(int i=a; i<=b; i++) bulb[i] = 1;
        }
    }
    
    for(int i=1; i<=n; i++) cout << bulb[i] << ' ';
    cout << '\n';
    
    return 0;
}
