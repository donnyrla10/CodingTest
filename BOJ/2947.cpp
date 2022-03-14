#include <iostream>
#include <algorithm>
using namespace std;

bool check(int wood[]){
    for(int i=1; i<5; i++)
        if(wood[i] > wood[i+1]) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int wood[6];
    for(int i=1; i<=5; i++) cin >> wood[i];
    
    while(check(wood)){
        for(int i=1; i<=4; i++){
            if(wood[i] > wood[i+1]){
                swap(wood[i], wood[i+1]);
                for(int i=1; i<=5; i++) cout << wood[i] << ' ';
                cout << '\n';
            }
        }
    }
    return 0;
}

